#pragma once
using namespace std;
void Fizika(Guest& G)
{
	int buf = 0;
	bool GG = false;
	cout << "" << endl;
	cout << "1 -    | " << "  2 -   |" << "  3 -  |" << " 4 -  ";
	while (GG)
	{
		int h;
		cin >> h;
		switch (h)
		{
		case 1:
		{
			buf++;
			GG = true;
			break;
		}
		case 2:
		{

			GG = true;
			break;
		}
		case 3:
		{
			GG = true;
			break;
		}
		case 4:
		{
			GG = true;
			break;
		}
		default:
		{
			cout << "Такого ответа нет! Пропробуй еще раз!" << endl;
		}
		}
	}
}