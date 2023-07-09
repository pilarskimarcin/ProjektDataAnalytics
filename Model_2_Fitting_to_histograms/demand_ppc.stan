data {
    int<lower=0> N;  // number of samples
    array[N] int<lower=0, upper=6> day_of_week;
    array[N] int<lower=1, upper=24> hour;
    array[7, 2] int coeffs_demand;
}

generated quantities {
    array[N] real demand;
    array[2] int coeffs;
    real alpha_demand;
    real beta_demand;
    real mu_demand;
    real theta;
    for (i in 1:N) {
        coeffs = coeffs_demand[day_of_week[i] + 1];
        alpha_demand = normal_rng(coeffs[1], 10);
        beta_demand = normal_rng(coeffs[2], 3000);
        mu_demand = alpha_demand * hour[i] + beta_demand;
        theta = beta_rng(1, 1);
        demand[i] = normal_rng(theta*(mu_demand - 2000) + (1-theta)*(mu_demand + 3000), 1);
    }
}