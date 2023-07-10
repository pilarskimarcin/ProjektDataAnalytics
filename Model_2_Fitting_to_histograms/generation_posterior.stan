data {
    int<lower=0> N;  // number of samples
    array[N] real wind_speed;
    array[N] real irradiance;
    array[N] real generation_samples;
}

parameters {
    real a_ws;
    real b_ws;
    real a_irr;
    real offset_;
}

model {
    a_ws ~ normal(-60, 10);
    b_ws ~ normal(1355, 100);
    a_irr ~ normal(-1.4, 0.1);
    offset_ ~ normal(3600, 500);
    for (i in 1:N) {
        generation_samples[i] ~ normal(a_ws * pow(wind_speed[i], 2) + b_ws * wind_speed[i] + a_irr * irradiance[i] + offset_, 1000);
        target += normal_lpdf(generation_samples[i] | a_ws * pow(wind_speed[i], 2) + b_ws * wind_speed[i] + a_irr * irradiance[i] + offset_, 1000);
    }
}

generated quantities {
    array[N] real generation;
    for (i in 1:N) {
        generation[i] = normal_rng(a_ws * pow(wind_speed[i], 2) + b_ws * wind_speed[i] + a_irr * irradiance[i] + offset_, 1000);
    }
}