#include <vector>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <stdlib.h> /* abs */
#include <numeric>

struct RecordArray {
    std::vector<simple_sparse_vector> data_vector;
    std::vector<double> labels_vector;
};

void Kernel_function(double x, double y)
{
    return;
};

class SVM 
{
private:
    string optim;
    WeightVector W;
    double C;
    double decision_function();
public:
    SVM(string optim, double C);
    ~SVM();
    void fit(RecordArray data);
    void test(RecordArray data);
};

void SVM::test()
{
    return decision_function();
};

SVM::SVM(string optim, double  C)
{
    this->optim = optim;
    this->C = C;
};

void SVM::fit(RecordArray data, int max_ilter=10)
{
    WeightVector *w;
    simple_sparse_vector x_0;
    Fesible_Region region = Fesible_Region();
    Optimization_objective opt_ojb = Optimization_objective();
    int t = 0;
    double step_size;

    if (this->optim == "fw")
    {
        while (t < max_ilter)
        {
            /* code */
            simple_sparse_vector gradient = opt_ojb.gradient_at(x_0);
            simple_sparse_vector dt = region.compute_extreme_point(gradient);
            x_0 = x_0 + step_size * dt;
        }
    }
    w = x_0;
};

class Dataset 
{ 
private:
    RecordArray array;
public: 
    Dataset();
    void read_dat_file(string file_name);
};

class Toolkit 
{
public:
    std::vector<RecordArray> split(double ratio, Dataset data);
    double back_tracking_line_search(Optimization_objective, simple_sparse_vector x, simple_sparse_vector direction, double max_lamda, double tau, double eps);
};

class Optimization_objective
{
public:
    simple_sparse_vector gradient_at(simple_sparse_vector weight);
    double primal_at(simple_sparse_vector weight);
};

class Unix_simplex: public Fesible_Region
{
public:
simple_sparse_vector solve(simple_sparse_vector gradient);
};

class Fesible_Region
{
public:
    simple_sparse_vector compute_extreme_point(simple_sparse_vector gradient);
};

class Cache
{
private:
    std::vector<simple_sparse_vector> previous_s;
    std::vector<double> alpha;
public:
    simple_sparse_vector argmin_s(simple_sparse_vector gradient);
    simple_sparse_vector argmax_s(simple_sparse_vector gradient);
};

class pcg
{
private:
    /* data */

public:
    pcg(Optimization_objective opt_obj, Fesible_Region region);
    ~pcg();
};

pcg::pcg(Optimization_objective opt_obj, Fesible_Region region)
{
}

pcg::~pcg()
{
}
