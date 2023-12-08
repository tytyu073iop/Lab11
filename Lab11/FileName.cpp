#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>
#include <limits>

int main() {
	std::vector<int> v;
	{
		std::string s;
		std::cin >> s;
		std::stringstream ss(s);
		while (ss.good()) {
			int t;
			ss >> t;
			v.push_back(t);
		}
	}
	{
		int sum = 0;
		std::for_each(v.begin(), v.end(), [&sum](const int& i) { sum += i; });
		std::cout << "sum: " << sum << "\ncount: " << v.size();
	}
	{
		int n;
		std::cin >> n;
		std::cout << "\nsame: " << std::count(v.begin(), v.end(), n) << "\n";
	}
	{
		std::cout << "if_count: " << std::count_if(v.begin(), v.end(), [](const int& i) { return i > 5;  });
	}
	{
		int sum = 0;
		std::for_each(v.begin(), v.end(), [&sum](const int& i) { sum += i; });
		int s = sum / v.size();
		std::replace(v.begin(), v.end(), 0, s);
		std::cout << "result of 0 -> mid\n";
		std::for_each(v.begin(), v.end(), [](const int& i) {std::cout << i << " "; });
		std::cout << '\n';
	}
	{
		int max = std::numeric_limits<int>::min();
		int min = std::numeric_limits<int>::max();
		std::for_each(v.begin(), v.end(), [&](const int& i) { if (min > i) { min = i; } if (max < i) { max = i; }});
		int r = max - min;
		std::replace_if(v.begin(), v.end(), [](const int& i) { return abs(i) % 2; }, r);
		std::cout << "result of odd -> r\n";
		std::for_each(v.begin(), v.end(), [](const int& i) {std::cout << i << " "; });
		std::cout << '\n';
	}
	{

	}
}