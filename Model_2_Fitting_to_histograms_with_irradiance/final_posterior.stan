data {
    // Samples
    int<lower=0> N_samples;  // number of samples
    array[N_samples] int<lower=0, upper=6> day_of_week_historic;
    array[N_samples] int<lower=1, upper=24> hour_historic;
    array[N_samples] real wind_speed_historic;
    array[N_samples] real irradiance_historic;
    array[N_samples] real prices_samples;
    // Prediction
    int<lower=0> N;  // number of samples in input for prediction
    array[N] int<lower=0, upper=6> day_of_week;
    array[N] int<lower=1, upper=24> hour;
    array[N] real wind_speed;
    array[N] real irradiance;
}

parameters {
    //Demand
    real a_hour;
    real b_hour;
    real a_day;
    real b_day;
    real offset_demand;
    array[N_samples] real demand_samples;
    // Generation
    real a_ws;
    real b_ws;
    real a_irr;
    real offset_generation;
    array[N_samples] real generation_samples;
    // Prices
    real a_demand;
    real a_generation;
    real offset_prices;
}

model {
        a_hour ~ normal(-32, 10);
        b_hour ~ normal(980, 10);
        a_day ~ normal(-300, 20);
        b_day ~ normal(1200, 100);
        offset_demand ~ normal(14500, 2000);

        a_ws ~ normal(-60, 10);
        b_ws ~ normal(1355, 100);
        a_irr ~ normal(-1.4, 0.1);
        offset_generation ~ normal(3600, 500);

        a_demand ~ normal(0.011, 0.001);
        a_generation ~ normal(-0.008, 0.0001);
        offset_prices ~ normal(51, 10);

    for (i in 1:N_samples) {
        int day = day_of_week[i];
        demand_samples[i] ~ normal(a_hour * pow(hour_historic[i], 2) + b_hour * hour_historic[i] + a_day * pow(day, 2) + b_day * day + offset_demand, 100);
        generation_samples[i] ~ normal(a_ws * pow(wind_speed_historic[i], 2) + b_ws * wind_speed_historic[i] + a_irr * irradiance_historic[i] + offset_generation, 1000);
        prices_samples[i] ~ normal(a_demand * demand_samples[i] + a_generation * generation_samples[i] + offset_prices, 100);
        target += normal_lpdf(prices_samples[i] | a_demand * demand_samples[i] + a_generation * generation_samples[i] + offset_prices, 100);
    }
}

generated quantities {
    array[N] real demand;
    array[N] real generation;
    array[N] real prices;
    for (i in 1:N) {
        int day = day_of_week[i];
        demand[i] = normal_rng(a_hour * pow(hour[i], 2) + b_hour * hour[i] + a_day * pow(day, 2) + b_day * day + offset_demand, 100);
        generation[i] = normal_rng(a_ws * pow(wind_speed[i], 2) + b_ws * wind_speed[i] + a_irr * irradiance[i] + offset_generation, 1000);
        prices[i] = normal_rng(a_demand * demand[i] + a_generation * generation[i] + offset_prices, 100);
    }
}