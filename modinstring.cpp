void modstr() {
	string s; cin >> s;
	int num; cin >> num;
	long long res = 0;
	for (int i = 0; i < s.size(); i++) {
		res *= 10;
		res += s[i] - '0';
		res %= num;
	}
	if (res == 0)cout << "YES";
	else cout << "NO";
}
