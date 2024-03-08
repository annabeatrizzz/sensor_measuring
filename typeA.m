% File
file = '../measurement_2.log';

% Reading from gile
f1 = fopen(file, 'r');
data = textscan(f1, 'Voltage (V): %f Resistance (Ohm): %f Temperature (ｰC): %f Temperature (ｰF): %f', 'delimiter', '\n');
fclose(f1);

% Adding the data to vectors
voltage = data{1};
resistance = data{2};
temperatureC = data{3};
temperatureF = data{4};

% Type A Uncertainty
N = length(voltage);  % Number of measurements

s_temperatureC = std(temperatureC);  % Standard Deviation for Temperature in Celsius
s_temperatureF = std(temperatureF);  % Standard Deviation for Temperature in Fahrenheit

u_temperatureC = s_temperatureC / sqrt(N);  % Type A Uncertainty for Temperature in Celsius
u_temperatureF = s_temperatureF / sqrt(N);  % Type A Uncertainty for Temperature in Fahrenheit

% Display
disp('Number of measurements:');
disp(N);

disp('Voltage Average:');
disp(mean(voltage));

disp('Resistance Average:');
disp(mean(resistance));

disp('Average Temperature in Celsius:');
disp(mean(temperatureC));

disp('Average Temperature in Fahrenheit:');
disp(mean(temperatureF));

disp('Type A Uncertainty for Temperature in Celsius:');
disp(u_temperatureC);

disp('Type A Uncertainty for Temperature in Fahrenheit:');
disp(u_temperatureF);
