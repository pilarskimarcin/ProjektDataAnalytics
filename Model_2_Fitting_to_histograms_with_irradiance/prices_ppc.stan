data {
    int<lower=0> N;  // number of samples
    array[N] real demand;
    array[N] real generation;
}

generated quantities {
    real a_demand;
    real a_generation;
    real offset_;
    array[N] real prices;
    for (i in 1:N) {
        a_demand = normal_rng(0.011, 0.001);
        a_generation = normal_rng(-0.008, 0.0001);
        offset_ = normal_rng(51, 10);
        prices[i] = normal_rng(a_demand * demand[i] + a_generation * generation[i] + offset_, 100);
    }
}