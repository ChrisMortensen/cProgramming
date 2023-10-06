#include <stdio.h>
#include <math.h>

int main(void) {
    int pointTotal;
    double totalLength = 0.0;
    
    printf("How many points do you have?\n");
    scanf("%d", &pointTotal);
    
    double x[pointTotal];
    double y[pointTotal];
    
    for (int i = 0; i < pointTotal; i++) {
        printf("Please provide x and y values for point %d.\n", i + 1);
        printf("x : ");
        scanf("%lf", &x[i]);  
        printf("y : ");
        scanf("%lf", &y[i]);  
	}
    
    for (int i = 0; i < pointTotal - 1; i++) {
        double dx = x[i + 1] - x[i];
        double dy = y[i + 1] - y[i];
        totalLength += sqrt(pow(dx,2) + pow(dy,2));
    }
    
    double dx = x[0] - x[pointTotal - 1];
    double dy = y[0] - y[pointTotal - 1];
    totalLength += sqrt(dx * dx + dy * dy);
    
    printf("Total length of the path is: %lf\n", totalLength);
    
    return 0;
}
