data {
    int<lower=0> N;  // number of samples
    array[N] real wind_speed;
}

generated quantities {
    real a_ws;
    real b_ws;
    real offset_;
    array[N] real generation;
    for (i in 1:N) {
        a_ws = normal_rng(-56, 10);
        b_ws = normal_rng(1323, 100);
        offset_ = normal_rng(3449, 600);
        generation[i] = normal_rng(a_ws * pow(wind_speed[i], 2) + b_ws * wind_speed[i] + offset_, 1000);
    }
}