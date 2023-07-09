data {
    int<lower=0> N;  // number of samples
    array[N] int<lower=0, upper=6> day_of_week;
    array[N] int<lower=1, upper=24> hour;
    array[7, 2] int coeffs_demand;
    array[N] real demand_samples;
}

parameters {
    vector[N] theta;
    real alpha_demand;
    real beta_demand;
}

transformed parameters {
    array[2] real coeffs;
    vector[N] mu_demand;
    for (i in 1:N) {
        coeffs = coeffs_demand[day_of_week[i] + 1];
        mu_demand[i] = alpha_demand * hour[i] + beta_demand;
    }
}

model {
    theta ~ beta(1, 1);
    alpha_demand ~ normal(coeffs[1], 10);
    beta_demand ~ normal(coeffs[2], 3000);
    demand_samples ~ normal(theta * (mu_demand - 2000.0) + (1 - theta) * (mu_demand + 3000.0), 1);
}

generated quantities {
    array[N] real demand;
    for (i in 1:N) {
        demand[i] = normal_rng(theta[i] * (mu_demand[i] - 2000.0) + (1 - theta[i]) * (mu_demand[i] + 3000.0), 1);
    }
}