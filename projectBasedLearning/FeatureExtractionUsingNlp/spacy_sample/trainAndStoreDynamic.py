from mainsdk import FeatureExtractor

import os, sys

# usage : first argument as data set , second as syntehsis data set

objSdkMain = FeatureExtractor()

objSdkMain.trainLabeledData(output_dir="ner_dynamic", import_datas_set=sys.argv[1], use_syntehsis=sys.argv[2], train_thresh=(70,30), only_dump_data=int(sys.argv[3]))

