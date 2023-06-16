data {
    int<lower=0> N;  // number of samples
    array[N] int day_of_week;
    array[N] int hour;
}

generated quantities {
    array[7, 6] real coeffs = {
        {-0.0950703760, 6.14994947, -145.486338, 1474.70424, -5158.13662, 20059.8441}, 
        {-0.0878203160, 5.62519133, -131.871194, 1330.29756, -4729.11895, 21332.4030}, 
        {-0.0963035781, 6.04350114, -137.821128, 1345.36611, -4648.44525, 21683.3403}, 
        {-0.0857723180, 5.45456535, -126.952039, 1272.63620, -4510.04698, 21538.1083}, 
        {-0.0810986775, 5.18096566, -121.186825, 1219.85827, -4339.87823, 21338.8750}, 
        {-0.0480872995, 3.15380473, -77.3493888, 841.564212, -3459.06662, 20447.6010}, 
        {-0.0448080230, 2.84113231, -67.0128103, 710.661245, -2946.40244, 18323.0422}
    };
    real theta;
    real mu;  // coeff[6] + (j from 1 to 5){coeff[j] * hour[i] ^ j}
    array[N] real demand;
    for (i in 1:N) {
        mu = 0;  // resetting value
        for (j in 1:5) {
            theta = normal_rng(coeffs[day_of_week[i] + 1][j], abs(0.005 * coeffs[day_of_week[i] + 1][j]));  // sigma = 0.5%
            mu += theta * hour[i] ^ (6 - j);  // adding coeff[j] * hour[i] ^ j
        }
        mu += normal_rng(coeffs[day_of_week[i] + 1][6], 100);  // adding coeff[6]
        demand[i] = normal_rng(mu, 1000);
    }
}