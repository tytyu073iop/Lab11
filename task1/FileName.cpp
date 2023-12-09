#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream> 
#include <string>
#include <vector>

int main() {
	std::vector<int> v;
	{
		std::string s;
                std::cout << "entry vector:\n";
                std::getline(std::cin, s);
		std::stringstream ss(s);
		while (ss.good()) {
			int t = 0;
			ss >> t;
			v.push_back(t);
                        // std::cout << "s" << s;
		}
                // std::cout << ss.rdstate() << ss.eof();
	}
	{
		int sum = 0;
		std::for_each(v.begin(), v.end(), [&sum](const int& i) { sum += i; });
		std::cout << "sum: " << sum << "\ncount: " << v.size();
	}
	{
		int n = 0;
                std::cout << "\nenter num to compare: ";
		std::cin >> n;
		std::cout << "same: " << std::count(v.begin(), v.end(), n) << "\n";
	}
	{
		std::cout << "if_count: " << std::count_if(v.begin(), v.end(), [](const int& i) { return i > 5;  });
	}
	{
		int sum = 0;
		std::for_each(v.begin(), v.end(), [&sum](const int& i) { sum += i; });
		int const s = sum / static_cast<int>(v.size());
		std::replace(v.begin(), v.end(), 0, s);
		std::cout << "\nresult of 0 -> mid\n";
		std::for_each(v.begin(), v.end(), [](const int& i) {std::cout << i << " "; });
		std::cout << '\n';
	}
	{
		int max = std::numeric_limits<int>::min();
		int min = std::numeric_limits<int>::max();
		std::for_each(v.begin(), v.end(), [&](const int& i) { if (min > i) { min = i; } if (max < i) { max = i; }});
		int const r = max - min;
		std::replace_if(v.begin(), v.end(), [](const int& i) { return abs(i) % 2; }, r);
		std::cout << "result of odd -> r\n";
		std::for_each(v.begin(), v.end(), [](const int& i) {std::cout << i << " "; });
		std::cout << '\n';
	}
	{
                auto i = std::unique(v.begin(),v.end(), [](const int& a, const int& b){ return abs(a) == abs(b); });
		std::cout << "result of rm\n";
		std::for_each(v.begin(), i, [](const int& i) {std::cout << i << " "; });
		std::cout << '\n';
	}
}
