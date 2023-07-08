data {
    int<lower=0> N_historic;  // Number of historical data points
    int<lower=0> N_predict;  // Number of prediction data points
    array[N_historic] real prices_historic;  // Historical prices for training
    array[N_historic] int day_of_week_historic;
    array[N_historic] int hour_historic;
    array[N_historic] real wind_speed_historic;
    array[7, 6] real coeffs_demand;
    array[4] real coeffs_generation;
    array[8] real coeffs_prices;
    array[N_predict] int day_of_week_predict;
    array[N_predict] int hour_predict;
    array[N_predict] real wind_speed_predict;
}

parameters {
   vector[N_historic] demand;
    vector[N_historic] generation;
}

transformed parameters {
    real mu_demand;  // coeff[6] + (j from 1 to 5){coeff[j] * hour[i] ^ (6-j)}
    for (i in 1:N_historic) {
        mu_demand = 0;  // resetting value
        for (j in 1:5) {
            mu_demand += coeffs_demand[day_of_week_historic[i] + 1][j] * hour_historic[i] ^ (6 - j);  // adding coeff[j] * hour[i] ^ j
        }
        mu_demand += coeffs_demand[day_of_week_historic[i] + 1][6];  // adding coeff[6]
    }

    real mu_generation;
    for (i in 1:N_historic) {
        mu_generation = 0;  // resetting value
        for (j in 1:3) {
            mu_generation += coeffs_generation[j] * wind_speed_historic[i] ^ (4 - j);  // adding coeff[j] * wind_speed[i] ^ j
        }
        mu_generation += coeffs_generation[4];  // adding coeff[4]
    }

    vector[N_historic] residual = demand - generation;
    real mu_prices;
    for (i in 1:N_historic) {
        mu_prices = 0;  // resetting value
        for (j in 1:7) {
            mu_prices += coeffs_prices[j] * residual[i] ^ (8 - j);  // adding coeff[j] * residual[i] ^ (8-j)
        }
        mu_prices += coeffs_prices[8];  // adding coeff[8]
    }
}

model {
    demand ~ normal(mu_demand, 2800);
    generation ~ normal(mu_generation, 1400);
    prices_historic ~ normal(mu_prices, 60);
}

generated quantities {
    real mu_demand_post;  // coeff[6] + (j from 1 to 5){coeff[j] * hour[i] ^ (6-j)}
    vector[N_predict] demand_post;
    for (i in 1:N_predict) {
        mu_demand_post = 0;  // resetting value
        for (j in 1:5) {
            mu_demand_post += coeffs_demand[day_of_week_predict[i] + 1][j] * hour_predict[i] ^ (6 - j);  // adding coeff[j] * hour[i] ^ j
        }
        mu_demand_post += coeffs_demand[day_of_week_predict[i] + 1][6];  // adding coeff[6]
        demand_post[i] = normal_rng(mu_demand_post, 2800);
    }

    real mu_generation_post;
    vector[N_predict] generation_post;
    for (i in 1:N_predict) {
        mu_generation_post = 0;  // resetting value
        for (j in 1:3) {
            mu_generation_post += coeffs_generation[j] * wind_speed_predict[i] ^ (4 - j);  // adding coeff[j] * wind_speed[i] ^ j
        }
        mu_generation_post += coeffs_generation[4];  // adding coeff[4]
        generation_post[i] = normal_rng(mu_generation_post, 1400);
    }

    vector[N_predict] residual_post = demand_post - generation_post;
    real mu_prices_post;
    array[N_predict] real posterior_prices;
    for (i in 1:N_predict) {
        mu_prices_post = 0;  // resetting value
        for (j in 1:7) {
            mu_prices_post += coeffs_prices[j] * residual_post[i] ^ (8 - j);  // adding coeff[j] * residual[i] ^ (8-j)
        }
        mu_prices_post += coeffs_prices[8];  // adding coeff[8]
        posterior_prices[i] = normal_rng(mu_prices_post, 60);
    }
}
