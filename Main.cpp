#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<algorithm>
#include<random>
#include<Windows.h>

using namespace std;


int pairs(vector<vector<string>> assignedList);
void showFullList(vector<string> kids, vector<string>);
void ifFree(vector<string> kids, vector<string> gifts, int a);
vector<string> addChild(vector<string>& kids, string name);
vector<string> addGift(vector<string>& gifts, string gift);
vector<string> shuffle(vector<string>& kids, vector<string>& gifts, vector<vector<string>>& assignedList);
vector<string> manuallyAssign(vector<string>& kids, vector<string>& gifts, vector<vector<string>>& assignedList);
void showPairedList(vector<vector<string>>& assignedList);
vector<string> assignAll(vector<string>& kids, vector<string>& gifts, vector<vector<string>>& assignedList);

int main()
{
	int choice;
	string name, gift;
	PlaySound(TEXT("test.wav"), NULL, SND_ASYNC);

	vector<string> kids = { "Dianne Ameter", "Bodrum Salvador", "Hilary Ouse", "Indigo Violet", "Hans Down", "Shequondolisa Bivouac", "Ingredia Nutrisha", "Fig Nelson", "Benjamin Evalent", "Gustav Purpleson", "Elon Gated", "Gootsy Porkins", "Cornbread Stevens", "Slaps Guster" };
	vector<string> gifts = { "Compass", "Banana", "Joystick", "Tamagotchi", "Drone", "Basketball ball", "Pear Watch", "Glasses", "Scooter", "Digimon", "Lego kit", "Internship", "Football ball", "Karaoke set" };
	vector<vector<string>> assignedList;

	//menu
	do {
		system("cls");
		cout << "\n	Santa's secret Christmas list !\n" << endl;
		cout << "	1. Show the list. " << endl;
		cout << "	2. How many children have their own gift ? " << endl;
		cout << "	3. How many children still don't have a gift? " << endl;
		cout << "	4. How many free gifts we have at this moment? " << endl;
		cout << "	5. Add new child to the list. " << endl;
		cout << "	6. Add new gift to the list. " << endl;
		cout << "	7. Shuffle, pair one kid + gift and remove paired from the list. " << endl;
		cout << "	8. Select a certain gift to a specific child. " << endl;
		cout << "	9. Show paired list. " << endl;
		cout << "	10. Assign all the gifts at once. " << endl;

		cout << "\n	11. Stop music. " << endl;
		cout << "	0. I'm done here. Exit. \n" << endl;
		cout << "	What is your selection ? - ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:	showFullList(kids, gifts);
			system("pause");
			break;
		case 2:	cout << "There are " << pairs(assignedList) << " kids, who have their gifts." << endl;
			system("pause");
			break;
		case 3:	ifFree(kids, gifts, 0);
			system("pause");
			break;
		case 4:	ifFree(kids, gifts, 1);
			system("pause");
			break;
		case 5: cout << "Enter name of the child :" << endl;
			cin.ignore();
			getline(cin, name);
			addChild(kids, name);
			system("pause");
			break;
		case 6: cout << "What gift you would like to add to the list :" << endl;
			cin.ignore();
			getline(cin, gift);
			addGift(gifts, gift);
			system("pause");
			break;
		case 7: shuffle(kids, gifts, assignedList);
			system("pause");
			break;
		case 8: manuallyAssign(kids, gifts, assignedList);
			system("pause");
			break;
		case 9: showPairedList(assignedList);
			system("pause");
			break;
		case 10: assignAll(kids, gifts, assignedList);
			system("pause");
			break;
		case 11: PlaySound(NULL, 0, 0);
			break;
		case 0:
			break;
		default: cout << "Entered option is incorrect. Try again !";
		}
	} while (choice != 0);

	return 0;
}





int pairs(vector<vector<string>> assignedList)
{
	int sizeOfAssignedPairs;

	sizeOfAssignedPairs = assignedList.size();

	return sizeOfAssignedPairs;
}

void showFullList(vector<string> kids, vector<string> gifts)
{
	cout << "Children's list :\n" << endl;
	for (int i = 0; i < kids.size(); i++) {
		cout << i + 1 << ". " << kids[i] << endl;
	}
	cout << "\nGifts list :\n" << endl;
	for (int i = 0; i < gifts.size(); i++) {
		cout << i + 1 << ". " << gifts[i] << endl;
	}
}

void ifFree(vector<string> kids, vector<string> gifts, int a)
{
	int temp = 0;
	// if a == 0, check kids. Else check gifts
	if (a == 0) {
		int temp = kids.size();
		if (temp > 0) { cout << "There is(are) " << temp << " unassigned kid(s)." << endl; }
		else { cout << "All children have gifts." << endl; }
	}
	else {
		int temp = gifts.size();
		if (temp > 0) { cout << "There is(are) " << temp << "unassigned gift(s)." << endl; }
		else { cout << "All gifts are rezerved." << endl; }
	}
}

vector<string> addChild(vector<string>& kids, string name)
{
	int temp = 0;

	for (int i = 0; i < kids.size(); i++) {
		if (kids[i].compare(name) != 0) {}
		else {
			cout << "There are children in the list with this name. Please try again." << endl;
			temp++;
		}
	}
	if (temp == 0) {
		kids.push_back(name);
		cout << "Children is added to the list." << endl;
	}
	return kids;
}

vector<string> addGift(vector<string>& gifts, string gift)
{
	gifts.push_back(gift);
	cout << "Gift is added to the list." << endl;

	return gifts;
}

vector<string> shuffle(vector<string>& kids, vector<string>& gifts, vector<vector<string>>& assignedList)
{
	auto rng = default_random_engine{};
	shuffle(begin(kids), end(kids), rng);
	shuffle(begin(gifts), end(gifts), rng);
	vector<string> temp;

	if (kids.size() != 0 && gifts.size() != 0) {
		temp.push_back(kids[0]);
		kids.erase(kids.begin());
		temp.push_back(gifts[0]);
		gifts.erase(gifts.begin());
		assignedList.push_back(temp);
		for (int i = 0; i < 2; i++) {
			temp.pop_back();
		}
	}
	cout << "Random child and gift are paired and removed from the list." << endl;

	return kids;
}

vector<string> manuallyAssign(vector<string>& kids, vector<string>& gifts, vector<vector<string>>& assignedList)
{
	int giftNumber, childNumber;
	vector<string> temp;

	for (int i = 0; i < gifts.size(); i++) {
		cout << i + 1 << ". - " << gifts[i] << endl;
	}
	cout << "\nWhich gift would you like to select. Enter the number of the gift :" << endl;
	cin.ignore();
	cin >> giftNumber;
	system("cls");

	for (int i = 0; i < kids.size(); i++) {
		cout << i + 1 << ". - " << kids[i] << endl;
	}
	cout << "\nNow please select a child. Enter the number of the child :" << endl;
	cin >> childNumber;
	system("cls");

	if (kids.size() != 0 && gifts.size() != 0) {
		temp.push_back(kids[childNumber - 1]);
		kids.erase(kids.begin());
		temp.push_back(gifts[giftNumber - 1]);
		gifts.erase(gifts.begin());
		assignedList.push_back(temp);
		for (int i = 0; i < 2; i++) {
			temp.pop_back();
		}
	}
	cout << "Child and gift are paired and removed from the list." << endl;

	return kids;
}

void showPairedList(vector<vector<string>>& assignedList)
{

	for (int i = 0, k = 0; i < assignedList.size(); i++) {
		cout << i + 1 << ". " << assignedList[i][k] << " - " << assignedList[i][k + 1] << endl;
	}
}

vector<string> assignAll(vector<string>& kids, vector<string>& gifts, vector<vector<string>>& assignedList)
{
	int kNumber, gNumber;
	vector<string> temp;

	kNumber = kids.size();
	gNumber = gifts.size();

	if (kNumber > gNumber) {
		kNumber = gNumber;
	}

	for (int i = 0; i < kNumber; i++) {
		temp.push_back(kids[0]);
		kids.erase(kids.begin());
		temp.push_back(gifts[0]);
		gifts.erase(gifts.begin());
		assignedList.push_back(temp);
		for (int i = 0; i < 2; i++) {
			temp.pop_back();
		}
	}
	cout << "All gifts were assigned." << endl;

	return kids;
}