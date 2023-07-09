data {
    int<lower=0> N;  // number of samples
    array[N] real wind_speed;
    int nu;  // degrees of freedom
    array[4] real coeffs;
}

generated quantities {
    real theta;
    real mu;  // coeff[4] + (j from 1 to 3){coeff[j] * wind_speed[i] ^ (4-j)}
    array[N] real generation;
    for (i in 1:N) {
        mu = 0;  // resetting value
        for (j in 1:3) {
            theta = coeffs[j];
            mu += theta * wind_speed[i] ^ (4 - j);  // adding coeff[j] * wind_speed[i] ^ j
        }
        mu += coeffs[4];  // adding coeff[4]
        generation[i] = student_t_rng(nu, mu, 1400);
    }
}