
int p, q, r, s, t, u;
double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;   // any function (algebric or Transcendental)
}
double bisection() {
	double lo = 0, hi = 1;
	while (lo + EPS < hi) {      // EPS small value like 1e-9
		double x = (lo + hi) / 2;
		if (f(lo) * f(x) <= 0) // there is a root between lo and x
			hi = x;
		else                   // there is a root between x and hi
			lo = x;
	}
    return lo;
}

int main()
{
    while (cin >> p >> q >> r >> s >> t >> u) {
		if (f(0) * f(1) > 0)   // if f(0) * f(1) < 0 means there is a root between 0 and 1
			cout << "No solution" << endl;
		else
			printf("%.4f\n", bisection());
	}
    return 0;
}
