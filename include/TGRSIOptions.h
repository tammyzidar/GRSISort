#ifndef TGRSIOPTIONS_H
#define TGRSIOPTIONS_H

#include <cstdio>
#include <string>

#include <TObject.h>

class TGRSIOptions : public TObject {

   private:
      static TGRSIOptions *fTGRSIOptions;
      TGRSIOptions();
   
   public:
      static TGRSIOptions *Get();
      virtual ~TGRSIOptions();


   private:
      std::string fhostname;
      std::string fexptname;
   
      std::vector<std::string> fInputRootFile;
      std::vector<std::string> fInputMidasFile;
      std::vector<std::string> fInputCalFile;
      std::vector<std::string> fInputOdbFile;

		static bool fCloseAfterSort;

   public:
      void SetHostName(std::string &host) {fhostname.assign(host);}
      void SetExptName(std::string &expt) {fexptname.assign(expt);}

      void AddInputRootFile(std::string &input)  {  fInputRootFile.push_back(input);    }
      void AddInputMidasFile(std::string &input) {  fInputMidasFile.push_back(input);   }
      void AddInputCalFile(std::string &input)   {  fInputCalFile.push_back(input);     }
      void AddInputOdbFile(std::string &input)   {  fInputOdbFile.push_back(input);     }

      std::string GetHostName()  {  return fhostname;  }
      std::string GetExptName()  {  return fexptname;  }
     
      std::vector<std::string> GetInputRoot()  {  return fInputRootFile;  }
      std::vector<std::string> GetInputMidas() {  return fInputMidasFile; }
      std::vector<std::string> GetInputCal()   {  return fInputCalFile;   }
      std::vector<std::string> GetInputOdb()   {  return fInputOdbFile;   }

		static void SetCloseAfterSort() { fCloseAfterSort = true; }
		static bool CloseAfterSort()    { return fCloseAfterSort; }

	   void Print(Option_t *opt = "");
      void Clear(Option_t *opt = "");


   ClassDef(TGRSIOptions,0)
};

#endif


