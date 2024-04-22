//// Привіт
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Train
{
private:
	int trainId;
	string destination;
	int allPlaces;
	int reservedPlaces;
public:
	Train()
	{
		trainId = 0;
		destination = "";
		allPlaces = 0;
		reservedPlaces = 0;
	}
	Train(int trainId, string destination, int allPlaces, int reservedPlaces)
	{
		this->trainId = trainId;
		this->destination = destination;
		this->allPlaces = allPlaces;
		this->reservedPlaces = reservedPlaces;
	}
	int getTrainId() 
	{
		return trainId;
	}
	void setTrainId(int trainId)   
	{
		this->trainId = trainId;
	}
	string getDestination()
	{
		return destination;
	}
	void setDestination(string destination)
	{
		this->destination = destination;
	}
	int getAllPlaces()
	{
		return allPlaces;
	}
	void setAllPlaces(int allPlaces)
	{
		this->allPlaces = allPlaces;
	}
	int getReservedPlaces()
	{
		return reservedPlaces;
	}
	void setReservedPlaces(int reservedPlaces)
	{
		this->reservedPlaces = reservedPlaces;
	}
	int getFreePlaces()
	{
		return allPlaces - reservedPlaces;
	}

Train()
    {
        trainId = 0;
        destination = "";
        allPlaces = 0;
        reservedPlaces = 0;
    }

Train(int trainId, string destination, int allPlaces, int reservedPlaces)
    {
        this->trainId = trainId;
        this->destination = destination;
        this->allPlaces = allPlaces;
        this->reservedPlaces = reservedPlaces;
    }
int getFreePlaces()
    {
       return allPlaces - reservedPlaces;
}
TicketsManager(string FileName)
    {
        ifstream InputFile;
        Train newTrain;
        InputFile.open(FileName);
        if (InputFile)
        {
            while (!InputFile.eof())
            {
                int trainId;
                string destination;
                int allPlaces;
                int reservedPlaces;
                InputFile >> trainId;
                InputFile >> destination;
                InputFile >> allPlaces;
                InputFile >> reservedPlaces;
                if (allPlaces < reservedPlaces)
                    reservedPlaces = allPlaces;

                newTrain.setTrainId(trainId);
                newTrain.setDestination(destination);
                newTrain.setAllPlaces(allPlaces);
                newTrain.setReservedPlaces(reservedPlaces);
                trainList.push_back(newTrain);
                //InputFile >> 
            }
            trainList.sort();// sort by increasing free places
            trainList.reverse();//reverse order of list
            cout << "Data has been read successfully!" << endl;
            InputFile.close();
        }
        else
            cout << "Error: couldn't be opened" << endl;
    }
void printToFileAvailableTrains(string outputFileName)
    {
        ofstream outputFile;
        outputFile.open(outputFileName);
            if (outputFile)
            {
                list<Train>::iterator trainListCopy;
                for (trainListCopy = trainList.begin(); trainListCopy != trainList.end(); trainListCopy++)
                {
                    if (trainListCopy->getFreePlaces() != 0)
                    {
                        outputFile << "Train id:" << trainListCopy->getTrainId() << endl;
                        outputFile << "Destiation: " << trainListCopy->getDestination() << endl;
                        outputFile << "All places: " << trainListCopy->getAllPlaces() << endl;
                        outputFile << "Reserved places: " << trainListCopy->getReservedPlaces() << endl;
                        outputFile << "Free places: " << trainListCopy->getFreePlaces() << endl;
                        outputFile << endl;
                    }
                }
                outputFile.close();
                cout << "Data has been written successfully!" << endl;
            }
            else
                cout << "Error: Output file hasn't been opened!" << endl;

    }


// Код основної програми
    TicketsManager MyManager = TicketsManager("Trains.txt");
    cout << endl << endl << endl;
    int menuOption = -1;

    while (menuOption != 4)
    {
        system("cls");
        cout << "1.Print all trains" << endl;
        cout << "2.Print available trains" << endl;
        cout << "3.Print available trains in file" << endl;
        cout << "4.Exit" << endl;
        cout << "Code of operation: ";
        cin >> menuOption;
        switch (menuOption)
        {
        case 1:
            system("cls");
            MyManager.printTrains();
            _getch();
            break;
        case 2:
            system("cls");
            MyManager.printAvailableTrains();
            _getch();
            break;
        case 3:
            system("cls");
            MyManager.printToFileAvailableTrains("Report.txt");
            _getch();
            break;
        case 4:
            system("cls");
            cout << "Program has finished" << endl;
            _getch();
            break;
        default:
            system("cls");
            cout << "Argument error" << endl;
            _getch();
        }
    }return 0;
