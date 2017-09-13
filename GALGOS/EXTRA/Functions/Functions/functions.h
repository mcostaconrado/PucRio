
void CalculateNorm(double* x, int sizeX, double* ret);

double* Projection_Symmetric(double* x, int sizeX);

double* Projection_Asymmetric1(double* x, int sizeX);

double* Projection_Asymmetric2(double* x, int sizeX);

//void GetSphericalRandomVector_Alpha(int sizeAlpha, double* ret);

void InnerProduct(double* x, double* y, int sizeXY, double* ret);

void Sign(double x, double* ret);

void Sign01(double x, double* ret);
