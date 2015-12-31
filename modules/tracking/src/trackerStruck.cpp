/*M///////////////////////////////////////////////////////////////////////////////////////
 //
 //  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
 //
 //  By downloading, copying, installing or using the software you agree to this license.
 //  If you do not agree to this license, do not download, install,
 //  copy or use the software.
 //
 //
 //                           License Agreement
 //                For Open Source Computer Vision Library
 //
 // Copyright (C) 2013, OpenCV Foundation, all rights reserved.
 // Third party copyrights are property of their respective owners.
 //
 // Redistribution and use in source and binary forms, with or without modification,
 // are permitted provided that the following conditions are met:
 //
 //   * Redistribution's of source code must retain the above copyright notice,
 //     this list of conditions and the following disclaimer.
 //
 //   * Redistribution's in binary form must reproduce the above copyright notice,
 //     this list of conditions and the following disclaimer in the documentation
 //     and/or other materials provided with the distribution.
 //
 //   * The name of the copyright holders may not be used to endorse or promote products
 //     derived from this software without specific prior written permission.
 //
 // This software is provided by the copyright holders and contributors "as is" and
 // any express or implied warranties, including, but not limited to, the implied
 // warranties of merchantability and fitness for a particular purpose are disclaimed.
 // In no event shall the Intel Corporation or contributors be liable for any direct,
 // indirect, incidental, special, exemplary, or consequential damages
 // (including, but not limited to, procurement of substitute goods or services;
 // loss of use, data, or profits; or business interruption) however caused
 // and on any theory of liability, whether in contract, strict liability,
 // or tort (including negligence or otherwise) arising in any way out of
 // the use of this software, even if advised of the possibility of such damage.
 //
 //M*/

#include "precomp.hpp"

/*---------------------------
|  TrackerStruckModel
|---------------------------*/
namespace cv{
   /**
  * \brief Implementation of TrackerModel for MIL algorithm
  */
  class TrackerStruckModel : public TrackerModel{
  public:
    TrackerStruckModel(TrackerStruck::Params /*params*/){}
    ~TrackerStruckModel(){}
  protected:
    void modelEstimationImpl( const std::vector<Mat>& responses ){}
    void modelUpdateImpl(){}
  };
} /* namespace cv */

/*---------------------------
|  TrackerStruck
|---------------------------*/ 
namespace cv
{
    /*
    * Prototype
    */
    class TrackerStruckImpl : public TrackerStruck
    {
    public:
        TrackerStruckImpl(const TrackerStruck::Params &parameters = TrackerStruck::Params());
        void read( const FileNode& fn );
        void write( FileStorage& fs ) const;

    protected:
        /*
        * basic functions and vars
        */
        bool initImpl( const Mat& /*image*/, const Rect2d& boundingBox );
        bool updateImpl( const Mat& image, Rect2d& boundingBox );

        TrackerStruck::Params params;
    }
    
    /*
    * Constructor
    */
    Ptr<TrackerStruck> TrackerStruck::createTracker(const TrackerStruck::Params &parameters){
        return Ptr<TrackerStruckImpl>(new TrackerStruckImpl(parameters));
    } 
    TrackerStruckImpl::TrackerStruckImpl( const TrackerStruck::Params &parameters ) :
        params( parameters )
    {
        isInit = false;
    }

    void TrackerStruckImpl::read( const cv::FileNode& fn ){
        params.read( fn );
    }

    void TrackerStruckImpl::write( cv::FileStorage& fs ) const{
        params.write( fs );
    }


    bool TrackerStruckImpl::initImpl( const Mat& image, const Rect2d& boundingBox )
    {
        model=Ptr<TrackerStruckModel>(new TrackerStruckModel(params));
        
        return true;
    }
    
    bool TrackerStruckImpl::updateImpl( const Mat& image, Rect2d& boundingBox ) 
    {
        return true;
    }

    
    /*
    * Parameters
    */
    TrackerStruck::Params::Params(){
        // TODO definir aqui os valores default dos params
    }

    void TrackerStruck::Params::read( const cv::FileNode& fn ){

    }

    void TrackerStruck::Params::write( cv::FileStorage& fs ) const{

    }

} /* namespace cv */