data {
    int<lower=0> N;  // number of samples
    array[N] int<lower=0, upper=6> day_of_week;
    array[N] int<lower=1, upper=24> hour;
    array[7, 2] int coeffs_demand;
}

generated quantities {
    //  = {
    //     {305, 16466},
    //     {218, 18296},
    //     {194, 18523},
    //     {202, 18429},
    //     {192, 18527},
    //     {91, 17488},
    //     {148, 14577}
    // };
    array[N] real demand;
    array[2] int coeffs;
    for (i in 1:N) {
        coeffs = coeffs_demand[day_of_week[i] + 1];
        demand[i] = coeffs[1] * hour[i] + coeffs[0];
    }
}