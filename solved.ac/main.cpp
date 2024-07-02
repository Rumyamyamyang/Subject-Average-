#include <iostream>
#include <vector>
#include <string>

struct Subject
{
	std::string name;
	int score;
};

int main()
{
	std::cout << "0 == stop input\n";

	int input{ 0 };

	int subjectNum{ 0 };
	std::cout << "Type number of subject : ";
	std::cin >> subjectNum;

	std::vector<int> aimAverage;
	std::cout << "Type your aim average score : ";
	while (true)
	{
		std::cin >> input;

		if (input == 0)
		{
			break;
		}
		aimAverage.push_back(input);
	}

	std::cout << "\n<Type all of your score (subject >> score)>\n";
	std::string inputSubject;
	int allScore{ 0 };
	std::vector<Subject> subjectInfo;

	while (true)
	{
		std::cin >> inputSubject;
		
		if (inputSubject == "0")
		{
			break;
		}
		std::cin >> input;
		
		subjectInfo.push_back(Subject(inputSubject, input));
		allScore += input;
	}
	std::cin.ignore();

	// ----Conclusion----
	// All score
	std::cout << "\n\n--------Your score--------\n";
	
	for (Subject subject : subjectInfo)
	{
		std::cout << subject.name << " : " << subject.score << '\n';
	}

	// Average
	std::cout << "\n\n--------Your goal--------";
	std::cout << "\nYour current average : " << allScore / subjectInfo.size();
	for (int i = 0; i < aimAverage.size(); ++i)
	{
		
		std::cout << "\n\nNeed this score to acheive your aim average " << aimAverage[i] << " : "
			<< (aimAverage[i] * subjectNum) - allScore;
		
	}
	std::cout << "\nLast subject Num : " << subjectNum - subjectInfo.size() << "\n\n";

	system("pause");

	return 0;
}