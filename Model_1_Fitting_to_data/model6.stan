data {
    int<lower=0> N;  // number of samples
    array[N] real residual;
    int nu;  // degrees of freedom
    array[8] real coeffs;
}

generated quantities {
    real theta;
    real mu;  // coeff[8] + (j from 1 to 7){coeff[j] * residual[i] ^ (8-j)}
    array[N] real prices;
    for (i in 1:N) {
        mu = 0;  // resetting value
        for (j in 1:7) {
            theta = coeffs[j];
            mu += theta * residual[i] ^ (8 - j);  // adding coeff[j] * residual[i] ^ (8-j)
        }
        mu += coeffs[8];  // adding coeff[8]
        prices[i] = student_t_rng(nu, mu, 60);
    }
}