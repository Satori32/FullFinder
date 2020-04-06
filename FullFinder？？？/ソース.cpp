#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

typedef std::vector<std::uintmax_t> DType;

DType MakeVector(std::size_t N, unsigned int S = 0) {
	std::minstd_rand mr(S);
	std::uniform_int_distribution<> ui(0, 16);

	DType R;

	for (std::size_t i = 0; i < N; i++) {
		R.push_back(ui(mr));
	}
	return R;
}

DType FullFindAndErase(const DType& D, const DType::value_type& V) {
	DType T = D;
	for (std::size_t i = 0; i < T.size(); i++) {
		if (T[i] == V) {
			T.erase(T.begin() + i);
			i--;
		}
	}

	return T;
}
DType FullFindAndEraseRange(const DType& D, const DType::value_type& Min,DType::value_type Max) {
	DType T = D;
	for (std::size_t i = 0; i < T.size(); i++) {
		if (T[i] >= Min && T[i] < Max) {
			T.erase(T.begin() + i);
			i--;
		}
	}

	return T;
}
int main() {
	DType D = MakeVector(64);
	DType D2 = D;
	for (std::size_t i = 0; i <= 16; i++) {
		D=FullFindAndErase(D, i);
	}

	D2 = FullFindAndEraseRange(D2, 6, 9);

	return 0;
}