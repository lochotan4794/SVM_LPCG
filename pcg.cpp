
#include "simple_sparse_vec_hash.h"
#include "pcg.h"
#include "WeightVector.h"


using namespace std;

int main(int argc, char **argv)
{
    string file_name = "data.dat";
    Dataset dataset =  Dataset();
    dataset.read_dat_file(file_name);
    Toolkit tool = Toolkit();
    SVM model = SVM();
    std::vector<RecordArray> sets = tool.split(0.3, dataset);
    RecordArray train_set = sets[0];
    RecordArray test_set = sets[1];
    model.fit(train_set);
    model.test(test_set);
    return (EXIT_SUCCESS);
}
