#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
void categorize_temperature(float celsius);
void convert_temperature();

int main() {
    convert_temperature();
    return 0;
}

// Convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

// Convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to categorize temperature and provide advisory
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\nWeather advisory: Stay warm indoors.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\nWeather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius <= 35) {
        printf("Temperature category: Hot\nWeather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors and avoid exertion.\n");
    }
}

// Function to handle temperature conversion
void convert_temperature() {
    float temperature;
    int input_scale, output_scale;
    float converted_temperature;

    // Input temperature value
    printf("Enter the temperature value: ");
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    // Input current scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
        printf("Invalid choice. Please select a valid option.\n");
        return;
    }

    // Input target scale
    printf("Choose the conversion target (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &output_scale) != 1 || output_scale < 1 || output_scale > 3) {
        printf("Invalid choice. Please select a valid option.\n");
        return;
    }

    // Conversion logic
    switch (input_scale) {
        case 1: // Celsius
            if (output_scale == 1) {
                converted_temperature = temperature;
            } else if (output_scale == 2) {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else {
                converted_temperature = celsius_to_kelvin(temperature);
            }
            break;
        case 2: // Fahrenheit
            if (output_scale == 1) {
                converted_temperature = fahrenheit_to_celsius(temperature);
            } else if (output_scale == 2) {
                converted_temperature = temperature;
            } else {
                converted_temperature = celsius_to_kelvin(fahrenheit_to_celsius(temperature));
            }
            break;
        case 3: // Kelvin
            if (temperature < 0) {
                printf("Invalid Kelvin value. Kelvin cannot be negative.\n");
                return;
            }
            if (output_scale == 1) {
                converted_temperature = kelvin_to_celsius(temperature);
            } else if (output_scale == 2) {
                converted_temperature = celsius_to_fahrenheit(kelvin_to_celsius(temperature));
            } else {
                converted_temperature = temperature;
            }
            break;
        default:
            printf("Invalid input scale.\n");
            return;
    }

    // Output converted temperature
    printf("Converted temperature: %.2f\n", converted_temperature);

    // Categorize and provide advisory based on the temperature in Celsius
    if (output_scale == 1) {
        categorize_temperature(converted_temperature);
    } else if (output_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temperature));
    } else {
        categorize_temperature(kelvin_to_celsius(converted_temperature));
    }
}