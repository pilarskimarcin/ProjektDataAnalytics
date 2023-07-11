data {
    int<lower=0> N;  // number of samples
    array[N] int<lower=0, upper=6> day_of_week;
    array[N] int<lower=1, upper=24> hour;
    array[N] real demand_samples;
}

parameters {
    real a_hour;
    real b_hour;
    real offset_;
    real a_day;
    real b_day;
}

model {
    a_hour ~ normal(-32, 10);
    b_hour ~ normal(980, 10);
    offset_ ~ normal(14500, 2000);
    a_day ~ normal(-300, 20);
    b_day ~ normal(1200, 100);
    for (i in 1:N) {
        int day = day_of_week[i];
        demand_samples[i] ~ normal(a_hour * pow(hour[i], 2) + b_hour * hour[i] + a_day * pow(day, 2) + b_day * day + offset_, 100);
        target += normal_lpdf(demand_samples[i] | a_hour * pow(hour[i], 2) + b_hour * hour[i] + a_day * pow(day, 2) + b_day * day + offset_, 100);
    }
}

generated quantities {
    array[N] real demand;
    for (i in 1:N) {
        int day = day_of_week[i];
        demand[i] = normal_rng(a_hour * pow(hour[i], 2) + b_hour * hour[i] + a_day * pow(day, 2) + b_day * day + offset_, 100);
    }
}