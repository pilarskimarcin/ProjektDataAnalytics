data {
    int<lower=0> N;  // number of samples
    array[N] real demand;
    array[N] real generation;
    array[N] real prices_samples;
}

parameters {
    real a_demand;
    real a_generation;
    real offset_;
}

model {
        a_demand ~ normal(0.011, 0.001);
        a_generation ~ normal(-0.008, 0.0001);
        offset_ ~ normal(51, 10);
    for (i in 1:N) {
        prices_samples[i] ~ normal(a_demand * demand[i] + a_generation * generation[i] + offset_, 100);
        target += normal_lpdf(prices_samples[i] | a_demand * demand[i] + a_generation * generation[i] + offset_, 100);
    }
}

generated quantities {
    array[N] real prices;
    for (i in 1:N) {
        prices[i] = normal_rng(a_demand * demand[i] + a_generation * generation[i] + offset_, 100);
    }
}