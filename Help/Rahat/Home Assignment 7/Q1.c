#include <stdio.h>

struct car
{
    int car_id;
    char brand_name[50];
    int model;
    int mileage;
} typedef car;

car get_latest(car[], int);
void read_car_array(car[], int, char[]);
void write_car(car, char[]);

int main()
{
    int n = 5;
    car latest;
    car cars[n];
    read_car_array(cars, n, "Q1_Input.txt");
    latest = get_latest(cars, n);
    write_car(latest, "Q1_Output.txt");
    return 0;
}

// return the lastest model car
car get_latest(car cars[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (cars[i].model > cars[index].model)
            index = i;
    }
    return cars[index];
}

// read car array from file
void read_car_array(car cars[], int n, char file_name[])
{
    FILE *fp;
    fp = fopen(file_name, "r");
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d %s %d %d", &cars[i].car_id, cars[i].brand_name, &cars[i].model, &cars[i].mileage);
    fclose(fp);
}

// write car to file
void write_car(car cars, char file_name[])
{
    FILE *fp;
    fp = fopen(file_name, "w");
    fprintf(fp, "ID: %d\nBrand: %s\nModel: %d\nMileage: %d\n", cars.car_id, cars.brand_name, cars.model, cars.mileage);
    fclose(fp);
}
