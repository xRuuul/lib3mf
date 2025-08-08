#include "UnitTest_Utilities.h"
#include "lib3mf_implicit.hpp"

namespace Lib3MF
{
    class ReaderOtherFiles : public Lib3MFTest {
        protected:
        virtual void SetUp() {
            model = wrapper->CreateModel();
            reader3MF = model->QueryReader("3mf");
        }
        virtual void TearDown() {
            model.reset();
            reader3MF.reset();
        }

        PModel model;
        PReader reader3MF;
    };

    TEST_F(ReaderOtherFiles, XReadFromFile)
    {
        std::cerr << "This test is for Bambu Lab 3MF files." << std::endl;
        ReaderOtherFiles::reader3MF->ReadFromFile(sTestFilesPath + "/Reader/" + "X.3mf");
        for (Lib3MF_uint32 iWarning = 0; iWarning < reader3MF->GetWarningCount(); iWarning++)
        {
            Lib3MF_uint32 nErrorCode;
            std::string sWarning = reader3MF->GetWarning(iWarning, nErrorCode);
            std::cerr << iWarning << ": " << nErrorCode << ", " << sWarning << std::endl;
        }
        
        CheckReaderWarnings(ReaderOtherFiles::reader3MF, 20);
    }

    TEST_F(ReaderOtherFiles, YReadFromFile)
    {
        ReaderOtherFiles::reader3MF->ReadFromFile(sTestFilesPath + "/Reader/" + "Y.3mf");
        for (Lib3MF_uint32 iWarning = 0; iWarning < reader3MF->GetWarningCount(); iWarning++)
        {
            Lib3MF_uint32 nErrorCode;
            std::string sWarning = reader3MF->GetWarning(iWarning, nErrorCode);
            std::cerr << iWarning << ": " << nErrorCode << ", " << sWarning << std::endl;
        }
        
        CheckReaderWarnings(ReaderOtherFiles::reader3MF, 0);
    }
}