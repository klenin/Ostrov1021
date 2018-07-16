#include <iostream>
#include <fstream>

#include "imgwarp_mls.h"

#include <vector>
#include <cv.h>

#include "imgwarp_piecewiseaffine.h"
#include "imgwarp_mls_rigid.h"
#include "imgwarp_mls_similarity.h"
#include "highgui.h"

using namespace std;

int main(int argc, char *argv[])
{
	ImgWarp_MLS *imgTrans;

	imgTrans = new ImgWarp_MLS_Similarity();
	
	// imgTrans = new ImgWarp_MLS_Rigid();

	// imgTrans = new ImgWarp_PieceWiseAffine();
	// ((ImgWarp_PieceWiseAffine *)imgTrans)->backGroundFillAlg = ImgWarp_PieceWiseAffine::BGMLS;
	
	ifstream points(argv[1]);

	vector<cv::Point2i> srcPoints, dstPoints;

	while (true) {
		int x1, y1, x2, y2;
		points >> x1 >> y1 >> x2 >> y2;
		if (points.eof()) {
			break;
		}
		x1 *= 4.65695;
		y1 *= 4.51925;
		srcPoints.push_back({x1, y1});
		dstPoints.push_back({x2, y2});
	}

	for (int i = 2; i < argc; i++) {
		cout << argv[i] << endl;
		Mat oriImg = cv::imread(argv[i]);
		Mat oriImgResized;
		cv::resize(oriImg, oriImgResized, {5756, 7276});

		Mat curImg = imgTrans->setAllAndGenerate(
				oriImgResized,
				srcPoints,
				dstPoints,
				oriImgResized.cols, oriImgResized.rows, 1);

		cv::imwrite(string("morphed_") + argv[i], curImg);
	}
}
