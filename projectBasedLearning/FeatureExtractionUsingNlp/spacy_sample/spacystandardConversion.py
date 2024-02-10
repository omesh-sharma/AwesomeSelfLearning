from mainsdk import FeatureExtractor

import os, sys

# usage : mode name and second argument as data set , thoird as syntehsis data set

objSdkMain = FeatureExtractor()

objSdkMain.trainLabeledData(output_dir="ner_dynamic", import_datas_set=sys.argv[1], use_syntehsis=sys.argv[2], only_dump_data=True, train_thresh=(70,30))

