#include <stdio.h>

struct SmartDevice {
	int deviceID;
	char deviceName;
	int status;
	float ratedPowerKW;
};

struct EnergySensor {
	float voltageVolts;
	float currentAmperes;
	int unoccupancyMinutes;
};

int main() {
	struct SmartDevice device;
	struct EnergySensor sensor;
	
	float operatingHours;
	float totalKWh;
	float totalCost;
	
	printf("--- NHAP THONG TIN THIET BI ---\n");
	
	printf("Nhap ma thiet bi: ");
	scanf("%d", &device.deviceID);
	
	printf("Nhap ten thiet bi: ");
	scanf(" %[^\n]", device.deviceName);
	
	printf("Trang thai (1-Bat, 0-Tat): ");
	scanf("%d", &device.status);
	
	printf("Nhap cong suat dinh muc(kW): ");
	scanf("%f", &device.ratedPowerKW);
	
	printf("\n--- NHAP THONG TIN CAM BIEN ---\n");
	
	printf("Dien ap (V): ");
	scanf("%f", &sensor.voltageVolts);
	
	printf("Dong dien (A): ");
	scanf("%f", &sensor.currentAmperes);
	
	printf("Thoi gian vang nguoi (phut): ");
	scanf("%d", &sensor.unoccupancyMinutes);
	
	if (sensor.voltageVolts < 0 || sensor.currentAmperes < 0 || sensor.unoccupancyMinutes < 0) {
		printf("\nLOI: Du lieu khong duoc am");
		return 0;
	}
	
	if (sensor.currentAmperes > 30.0f) {
		device.status = 0;
		
		printf("\nCANH BAO NGUY HIEM! Dong dien vuot qua 30A, he thong tu dong ngat dien.\n");
	} else {
		if (device.status == 1 && sensor.unoccupancyMinutes >= 15) {
			device.status = 0;
			
			printf("\nCANH BAO TIET KIEM NANG LUONG! Phong vang nguoi hon 15 phut, he thong tu dong ngat dien.\n");
		}
	}
	
	printf("\n--- NHAP THOI GIAN VAN HANH ---\n");
	
	printf("Nhap so gio van hanh trong thang: ");
	scanf("%f", &operatingHours);
	
	if (operatingHours <= 0 || operatingHours > 744) {
		printf("\nLOI: So gio phai lon hon 0 va nho hon 744 gio.\n");
		
		return 0;
	}
	
	totalKWh = device.ratedPowerKW * operatingHours;
	
	if (totalKWh <= 50) {
		totalCost = totalKWh * 1806;
	} else if (totalKWh <= 100) {
		totalCost = 50 * 1806 + (totalKWh - 50) * 1866;
	} else if (totalKWh <= 200) {
		totalCost = 50 * 1806 + 50 * 1866 + (totalKWh -100) * 2167;
	} else {
		totalCost = 50 * 1806 + 50 * 1866 + 100 * 2167 + (totalKWh - 200) * 2729;
	}
	
	printf("--- BAO CAO THIET BI THONG MINH ---");
	printf("Ma thiet bi: %d\n", device.deviceID);
	printf("Ten thiet bi: %s\n", device.deviceName);
	
	if (device.status == 1) {
		printf("Trang thai: DANG BAT\n");
	} else {
		printf("Trang thai: DA TAT\n");
	}
	
	printf("Cong suat dinh muc: %.2f kW\n", device.ratedPowerKW);
	printf("Dien ap: %.2f V\n", sensor.voltageVolts);
	printf("Dong dien: %.2f A\n", sensor.currentAmperes);
	printf("Thoi gian vang nguoi: %d phut\n", sensor.unoccupancyMinutes);
	printf("Thoi gian van hanh: %.2f gio\n", operatingHours);
	printf("Tong dien nang: %.2f kWh\n", totalKWh);
	printf("Tong tien dien: %.0f VND\n", totalCost);
	
	return 0;
}




















