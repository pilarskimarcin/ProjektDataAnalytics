data {
    int<lower=0> N;  // number of samples
    array[N] int<lower=0, upper=6> day_of_week;
    array[N] int<lower=1, upper=24> hour;
}

generated quantities {
    real a_hour;
    real b_hour;
    real offset_;
    real a_day;
    real b_day;
    int day;
    array[N] real demand;
    for (i in 1:N) {
        a_hour = normal_rng(-32, 10);
        b_hour = normal_rng(980, 10);
        offset_ = normal_rng(14500, 2000);
        a_day = normal_rng(-300, 20);
        b_day = normal_rng(1200, 100);
        day = day_of_week[i];
        demand[i] = normal_rng(a_hour * pow(hour[i], 2) + b_hour * hour[i] + a_day * pow(day, 2) + b_day * day + offset_, 100);
    }
}