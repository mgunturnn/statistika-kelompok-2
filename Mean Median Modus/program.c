#include <stdio.h>

#define NUM_CLASSES 1
#define MAX_DATA_POINTS 30

int data[NUM_CLASSES][MAX_DATA_POINTS] = {
    {82, 69, 82, 90, 75, 73, 82, 80, 65, 79, 74, 94, 89, 90, 76, 92, 79, 74, 75, 91, 90, 84, 81, 69, 89, 77, 90, 81, 86, 83}};

int data_count[NUM_CLASSES] = {MAX_DATA_POINTS};

float mean(int *values, int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += values[i];
    }
    return (float)sum / count;
}

float median(int *values, int count)
{
    // First, sort the values
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (values[j] < values[i])
            {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    // If there are an odd number of values, return the middle one
    if (count % 2 == 1)
    {
        return (float)values[count / 2];
    }
    // If there are an even number of values, return the average of the middle two
    else
    {
        return (float)(values[count / 2] + values[count / 2 - 1]) / 2;
    }
}

int mode(int *values, int count)
{
    int max_count = 0;
    int mode_value = 0;
    for (int i = 0; i < count; i++)
    {
        int current_count = 0;
        for (int j = 0; j < count; j++)
        {
            if (values[j] == values[i])
            {
                current_count++;
            }
        }
        if (current_count > max_count)
        {
            max_count = current_count;
            mode_value = values[i];
        }
    }
    return mode_value;
}

int main()
{
    // Calculate the mean, median, and mode for each class
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        system("cls");
        float mean_value = mean(data[i], data_count[i]);
        float median_value = median(data[i], data_count[i]);
        int mode_value = mode(data[i], data_count[i]);
        printf("Result: \n");
        printf("Mean : %f \n", mean_value);
        printf("Median : %f \n", median_value);
        printf("Modus : %d \n", mode_value);
    }
    return 0;
}
