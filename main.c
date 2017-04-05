#include <iostream>
#include <stdlib.h>
#include <dirent.h>

using namespace std;

void check_usage(int, char**);
void print_usage();
void check_directory_existence(char*);
void read_directory(char*);

int main(int argc, char *argv[])
{
	check_usage(argc, argv);
	cout << "Usage seems OK...\n";

	cout << "Module Search Operation...\n";
	read_directory(argv[1]);
	return 0;
}

void read_directory(char* base_path)
{
	DIR* dp;
	dp = opendir(base_path);
	struct dirent *temp;
	temp = readdir(dp);
	cout << temp->d_name;
}

void check_usage(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect usage\n";
		print_usage();
		exit(1);
	}
	else
	{
		check_directory_existence(argv[1]);
	}
}

void print_usage()
{
	cout << "Correct Usage: binary directory_path module_name\n";
}

void check_directory_existence(char* base_path)
{
        DIR* dir = opendir(base_path);
	if (dir)
	{
    		/* Directory exists. */
    		closedir(dir);
	}
	else
	{
    	    /* opendir() failed for some other reason. */
	    cout << "Unable to read directory!\n";
	    exit(1);
	}
}
