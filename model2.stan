data {
    int<lower=0> N;  // number of samples
    array[N] int day_of_week;
    array[N] int hour;
    int nu;  // degrees of freedom
    array[7, 6] real coeffs;
}

generated quantities {
    real theta;
    real mu;  // coeff[6] + (j from 1 to 5){coeff[j] * hour[i] ^ (6-j)}
    array[N] real demand;
    for (i in 1:N) {
        mu = 0;  // resetting value
        for (j in 1:5) {
            theta = coeffs[day_of_week[i] + 1][j];
            mu += theta * hour[i] ^ (6 - j);  // adding coeff[j] * hour[i] ^ j
        }
        mu += coeffs[day_of_week[i] + 1][6];  // adding coeff[6]
        demand[i] = student_t_rng(nu, mu, 2800);
    }
}