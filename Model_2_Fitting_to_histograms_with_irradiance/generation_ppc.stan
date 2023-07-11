data {
    int<lower=0> N;  // number of samples
    array[N] real wind_speed;
    array[N] real irradiance;
}

generated quantities {
    real a_ws;
    real b_ws;
    real a_irr;
    real offset_;
    array[N] real generation;
    for (i in 1:N) {
        a_ws = normal_rng(-60, 10);
        b_ws = normal_rng(1355, 100);
        a_irr = normal_rng(-1.4, 0.1);
        offset_ = normal_rng(3600, 500);
        generation[i] = normal_rng(a_ws * pow(wind_speed[i], 2) + b_ws * wind_speed[i] + a_irr * irradiance[i] + offset_, 1000);
    }
}