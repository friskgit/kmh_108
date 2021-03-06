/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_5h3v_normal_6"
version: "1.2"
Code generated with Faust 2.6.3 (https://faust.grame.fr)
Compilation options: cpp, -double -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************

    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2004-2028 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

    MAX MSP SDK : in order to compile a MaxMSP external with this
    architecture file you will need the official MaxMSP SDK from
    cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

#define FAUSTFLOAT double

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;
        std::string fOptions;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fDSPSize;
        std::map<std::string, int> fPathTable;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        // Add escape (that is  '\') for internal strings
        inline std::string flatten(const std::string& src)
        {
            bool in_string = false;
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    case ' ':
                        if (in_string) dst << src[i];
                        break;
                    case '"':
                        dst << "\\" << '"';
                        in_string = !in_string;
                        break;
                    case '\\':
                        dst << '\\' << '\\';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        inline std::string getAddressIndex(const std::string& path)
        {
            if (fPathTable.find(path) != fPathTable.end()) {
                std::stringstream num; num << fPathTable[path];
                return num.str();
            } else {
                return "-1";
            }
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sha_key, dsp_code,  version, options, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, "", "", "", "", "", std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, "", "","", "", "", std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, "", "", "", "", "", std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            fTab = 1;
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fOptions = options;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            tab(fTab, fJSON); fJSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, fJSON); fJSON << "\"version\": \"" << fVersion << "\","; }
            if (fOptions != "") { tab(fTab, fJSON); fJSON << "\"options\": \"" << fOptions << "\","; }
            if (fDSPSize != "") { tab(fTab, fJSON); fJSON << "\"size\": \"" << fDSPSize << "\","; }
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}";
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& options,
               const std::string& size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sha_key, dsp_code,
                              version, options,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
    
        virtual std::vector<std::string> getDSPFactoryLibraryList() = 0;
        virtual std::vector<std::string> getDSPFactoryIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


#ifdef POLY2
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>


// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
    
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
    
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
    
        FAUSTFLOAT** fInputsDSP2;
        FAUSTFLOAT** fOutputsDSP2;
    
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            fInputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fOutputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
            delete [] fInputsDSP2;
            delete [] fOutputsDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
        
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fInputsDSP2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fOutputsDSP2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, fInputsDSP2, fOutputsDSP2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
#include "effect.cpp"
#endif

#if SOUNDFILE
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __soundfile__
#define __soundfile__

#include <sndfile.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE     1024
#define SAMPLE_RATE     44100
#define MAX_CHAN        64

#define MIN_CHAN(a,b) ((a) < (b) ? (a) : (b))

#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))

PRE_PACKED_STRUCTURE
struct Soundfile {
    
    FAUSTFLOAT** fBuffers;
    int fLength;
    int fSampleRate;
    int fChannels;
    
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
    
    static std::string CheckAux(const std::string& path_name_str, std::string& sha_key)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            // Possibly read associated SHA_KEY file
            std::string sha_key_path_name_str = path_name_str + "_sha_key";
            std::ifstream reader(sha_key_path_name_str.c_str());
            if (reader.is_open()) {
                std::string sha_key_line;
                getline(reader, sha_key_line);
                std::stringstream line_reader(sha_key_line);
                line_reader >> sha_key;
            }
            return path_name_str;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name_str << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return "";
        }
    }
    
    // Check if soundfile exists and return the real path_name
    static std::string Check(const std::vector<std::string>& sound_directories, const std::string& file_name_str, std::string& sha_key)
    {
        std::string path_name_str = CheckAux(file_name_str, sha_key);
        if (path_name_str != "") {
            return path_name_str;
        } else {
            for (int i = 0; i < sound_directories.size(); i++) {
                std::string res = CheckAux(sound_directories[i] + "/" + file_name_str, sha_key);
                if (res != "") { return res; }
            }
            return "";
        }
    }
    
    Soundfile(const std::string& path_name_str, int max_chan)
    {
        fBuffers = new FAUSTFLOAT*[max_chan];
        if (!fBuffers) {
            throw std::bad_alloc();
        }
     
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        
        if (snd_file) {
            
            fChannels = MIN_CHAN(max_chan, snd_info.channels);
            fLength = int(snd_info.frames);
            fSampleRate = snd_info.samplerate;
            
            for (int chan = 0; chan < fChannels; chan++) {
                fBuffers[chan] = new FAUSTFLOAT[snd_info.frames];
                if (!fBuffers[chan]) {
                    throw std::bad_alloc();
                }
            }
            
            // Read and fill snd_info.channels number of channels
            sf_count_t nbf, index = 0;
            FAUSTFLOAT buffer[BUFFER_SIZE * snd_info.channels];
            sample_read reader;
            if (sizeof(FAUSTFLOAT) == 4) {
                reader = reinterpret_cast<sample_read>(sf_readf_float);
            } else {
                reader = reinterpret_cast<sample_read>(sf_readf_double);
            }
            do {
                nbf = reader(snd_file, buffer, BUFFER_SIZE);
                for (int sample = 0; sample < nbf; sample++) {
                    for (int chan = 0; chan < fChannels; chan++) {
                        fBuffers[chan][index + sample] = buffer[sample * snd_info.channels + chan];
                    }
                }
                index += nbf;
            } while (nbf == BUFFER_SIZE);
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[chan % snd_info.channels];
            }
       
            sf_close(snd_file);
            
        } else {
            
            if (path_name_str != "") {
                std::cerr << "Error opening the file : " << path_name_str << std::endl;
            }
            
            fChannels = 1;
            fLength = BUFFER_SIZE;
            fSampleRate = SAMPLE_RATE;
            
            // Allocate 1 channel
            fBuffers[0] = new FAUSTFLOAT[BUFFER_SIZE];
            if (!fBuffers[0]) {
                throw std::bad_alloc();
            }
            memset(fBuffers[0], 0, BUFFER_SIZE * sizeof(FAUSTFLOAT));
            
            // Share the same buffer for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[0];
            }
        }
    }
    
    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete [] fBuffers;
    }
    
} POST_PACKED_STRUCTURE;

#endif

// To be used by dsp code if no SoundUI is used or when soundfile is not found
extern "C" Soundfile* defaultsound = new Soundfile("", MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;        // The soundfile directories
        std::map<std::string, Soundfile*> fSFMap;      // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_directory = "")
        {
            fSoundfileDir.push_back(sound_directory);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories):fSoundfileDir(sound_directories)
        {}
    
        virtual ~SoundUI()
        {   
            // delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSFMap.begin(); it != fSFMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* file_name, Soundfile** sf_zone)
        {
            // If no filename was given, assume label is the filename
            std::string file_name_str;
            if (strlen(file_name) == 0) {
                file_name_str = label;
            } else {
                file_name_str = file_name;
            }
            
            std::string sha_key;
            std::string path_name_str = Soundfile::Check(fSoundfileDir, file_name_str, sha_key);
            if (path_name_str != "") {
                std::string file_key = (sha_key == "") ? path_name_str : sha_key;
                // Check if 'file_key' is already loaded
                if (fSFMap.find(file_key) == fSFMap.end()) {
                    fSFMap[file_key] = new Soundfile(path_name_str, 64);
                }
                // Get the soundfile
                *sf_zone = fSFMap[file_key];
            } else {
                // Take the defaultsound
                std::cout << "addSoundfile : defaultsound\n";
                *sf_zone = defaultsound;
            }
        }
    
    static std::string getBinaryPath(std::string folder = "")
    {
        std::string bundle_path_str;
    #ifdef __APPLE__
        CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
        if (bundle_ref) {
            UInt8 bundle_path[512];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                bundle_path_str = std::string((char*)bundle_path) + folder;
            }
        }
    #endif
        return bundle_path_str;
    }
    
    static std::string getBinaryPathFrom(const std::string& path)
    {
        std::string bundle_path_str;
    #ifdef __APPLE__
        CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
        CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
        if (bundle_ref) {
            UInt8 bundle_path[512];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                bundle_path_str = std::string((char*)bundle_path);
            }
        }
    #endif
        return bundle_path_str;
    }
};

#endif
#endif

using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

double mydsp_faustpower2_f(double value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	double fRec0[2];
	int fSamplingFreq;
	int iConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	FAUSTFLOAT fHslider1;
	double fRec17[2];
	double fRec16[3];
	FAUSTFLOAT fHslider2;
	double fRec18[2];
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fConst11;
	double fConst12;
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fRec3[2];
	double fRec1[2];
	double fConst13;
	double fConst14;
	double fRec29[3];
	double fRec30[3];
	double fRec31[3];
	double fConst15;
	double fRec28[2];
	double fRec26[2];
	double fConst16;
	double fConst17;
	double fConst18;
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fRec50[3];
	double fRec51[3];
	double fConst19;
	double fConst20;
	double fRec43[2];
	double fRec41[2];
	double fRec40[2];
	double fRec38[2];
	double fConst21;
	double fConst22;
	double fRec37[2];
	double fRec35[2];
	double fRec34[2];
	double fRec32[2];
	double fConst23;
	double fConst24;
	double fRec58[3];
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fConst25;
	double fConst26;
	double fRec57[2];
	double fRec55[2];
	double fRec54[2];
	double fRec52[2];
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fRec72[3];
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fRec77[3];
	double fRec78[3];
	double fConst31;
	double fConst32;
	double fRec71[2];
	double fRec69[2];
	double fRec68[2];
	double fRec66[2];
	double fRec65[2];
	double fRec63[2];
	double fRec79[3];
	int IOTA;
	double fVec0[1024];
	int iConst33;
	double fRec91[2];
	double fRec89[2];
	double fRec88[2];
	double fRec86[2];
	double fRec85[2];
	double fRec83[2];
	double fRec82[2];
	double fRec80[2];
	double fRec100[2];
	double fRec98[2];
	double fRec97[2];
	double fRec95[2];
	double fRec94[2];
	double fRec92[2];
	double fRec106[2];
	double fRec104[2];
	double fRec103[2];
	double fRec101[2];
	double fRec121[2];
	double fRec119[2];
	double fRec118[2];
	double fRec116[2];
	double fRec115[2];
	double fRec113[2];
	double fRec112[2];
	double fRec110[2];
	double fRec109[2];
	double fRec107[2];
	double fRec124[2];
	double fRec122[2];
	double fVec1[1024];
	double fRec139[2];
	double fRec137[2];
	double fRec136[2];
	double fRec134[2];
	double fRec133[2];
	double fRec131[2];
	double fRec130[2];
	double fRec128[2];
	double fRec127[2];
	double fRec125[2];
	double fRec151[2];
	double fRec149[2];
	double fRec148[2];
	double fRec146[2];
	double fRec145[2];
	double fRec143[2];
	double fRec142[2];
	double fRec140[2];
	double fRec160[2];
	double fRec158[2];
	double fRec157[2];
	double fRec155[2];
	double fRec154[2];
	double fRec152[2];
	double fRec163[2];
	double fRec161[2];
	double fRec169[2];
	double fRec167[2];
	double fRec166[2];
	double fRec164[2];
	double fVec2[1024];
	double fRec175[2];
	double fRec173[2];
	double fRec172[2];
	double fRec170[2];
	double fRec178[2];
	double fRec176[2];
	double fRec193[2];
	double fRec191[2];
	double fRec190[2];
	double fRec188[2];
	double fRec187[2];
	double fRec185[2];
	double fRec184[2];
	double fRec182[2];
	double fRec181[2];
	double fRec179[2];
	double fRec202[2];
	double fRec200[2];
	double fRec199[2];
	double fRec197[2];
	double fRec196[2];
	double fRec194[2];
	double fRec214[2];
	double fRec212[2];
	double fRec211[2];
	double fRec209[2];
	double fRec208[2];
	double fRec206[2];
	double fRec205[2];
	double fRec203[2];
	double fVec3[1024];
	double fRec229[2];
	double fRec227[2];
	double fRec226[2];
	double fRec224[2];
	double fRec223[2];
	double fRec221[2];
	double fRec220[2];
	double fRec218[2];
	double fRec217[2];
	double fRec215[2];
	double fRec241[2];
	double fRec239[2];
	double fRec238[2];
	double fRec236[2];
	double fRec235[2];
	double fRec233[2];
	double fRec232[2];
	double fRec230[2];
	double fRec250[2];
	double fRec248[2];
	double fRec247[2];
	double fRec245[2];
	double fRec244[2];
	double fRec242[2];
	double fRec253[2];
	double fRec251[2];
	double fRec259[2];
	double fRec257[2];
	double fRec256[2];
	double fRec254[2];
	double fVec4[1024];
	double fRec274[2];
	double fRec272[2];
	double fRec271[2];
	double fRec269[2];
	double fRec268[2];
	double fRec266[2];
	double fRec265[2];
	double fRec263[2];
	double fRec262[2];
	double fRec260[2];
	double fRec286[2];
	double fRec284[2];
	double fRec283[2];
	double fRec281[2];
	double fRec280[2];
	double fRec278[2];
	double fRec277[2];
	double fRec275[2];
	double fRec295[2];
	double fRec293[2];
	double fRec292[2];
	double fRec290[2];
	double fRec289[2];
	double fRec287[2];
	double fRec298[2];
	double fRec296[2];
	double fRec304[2];
	double fRec302[2];
	double fRec301[2];
	double fRec299[2];
	double fVec5[1024];
	double fRec319[2];
	double fRec317[2];
	double fRec316[2];
	double fRec314[2];
	double fRec313[2];
	double fRec311[2];
	double fRec310[2];
	double fRec308[2];
	double fRec307[2];
	double fRec305[2];
	double fRec328[2];
	double fRec326[2];
	double fRec325[2];
	double fRec323[2];
	double fRec322[2];
	double fRec320[2];
	double fRec331[2];
	double fRec329[2];
	double fRec337[2];
	double fRec335[2];
	double fRec334[2];
	double fRec332[2];
	double fRec349[2];
	double fRec347[2];
	double fRec346[2];
	double fRec344[2];
	double fRec343[2];
	double fRec341[2];
	double fRec340[2];
	double fRec338[2];
	double fVec6[1024];
	double fRec358[2];
	double fRec356[2];
	double fRec355[2];
	double fRec353[2];
	double fRec352[2];
	double fRec350[2];
	double fRec364[2];
	double fRec362[2];
	double fRec361[2];
	double fRec359[2];
	double fRec367[2];
	double fRec365[2];
	double fRec379[2];
	double fRec377[2];
	double fRec376[2];
	double fRec374[2];
	double fRec373[2];
	double fRec371[2];
	double fRec370[2];
	double fRec368[2];
	double fRec394[2];
	double fRec392[2];
	double fRec391[2];
	double fRec389[2];
	double fRec388[2];
	double fRec386[2];
	double fRec385[2];
	double fRec383[2];
	double fRec382[2];
	double fRec380[2];
	double fVec7[1024];
	double fRec409[2];
	double fRec407[2];
	double fRec406[2];
	double fRec404[2];
	double fRec403[2];
	double fRec401[2];
	double fRec400[2];
	double fRec398[2];
	double fRec397[2];
	double fRec395[2];
	double fRec421[2];
	double fRec419[2];
	double fRec418[2];
	double fRec416[2];
	double fRec415[2];
	double fRec413[2];
	double fRec412[2];
	double fRec410[2];
	double fRec430[2];
	double fRec428[2];
	double fRec427[2];
	double fRec425[2];
	double fRec424[2];
	double fRec422[2];
	double fRec433[2];
	double fRec431[2];
	double fRec439[2];
	double fRec437[2];
	double fRec436[2];
	double fRec434[2];
	double fVec8[1024];
	double fRec454[2];
	double fRec452[2];
	double fRec451[2];
	double fRec449[2];
	double fRec448[2];
	double fRec446[2];
	double fRec445[2];
	double fRec443[2];
	double fRec442[2];
	double fRec440[2];
	double fRec457[2];
	double fRec455[2];
	double fRec463[2];
	double fRec461[2];
	double fRec460[2];
	double fRec458[2];
	double fRec472[2];
	double fRec470[2];
	double fRec469[2];
	double fRec467[2];
	double fRec466[2];
	double fRec464[2];
	double fRec484[2];
	double fRec482[2];
	double fRec481[2];
	double fRec479[2];
	double fRec478[2];
	double fRec476[2];
	double fRec475[2];
	double fRec473[2];
	double fVec9[1024];
	double fRec499[2];
	double fRec497[2];
	double fRec496[2];
	double fRec494[2];
	double fRec493[2];
	double fRec491[2];
	double fRec490[2];
	double fRec488[2];
	double fRec487[2];
	double fRec485[2];
	double fRec511[2];
	double fRec509[2];
	double fRec508[2];
	double fRec506[2];
	double fRec505[2];
	double fRec503[2];
	double fRec502[2];
	double fRec500[2];
	double fRec520[2];
	double fRec518[2];
	double fRec517[2];
	double fRec515[2];
	double fRec514[2];
	double fRec512[2];
	double fRec523[2];
	double fRec521[2];
	double fRec529[2];
	double fRec527[2];
	double fRec526[2];
	double fRec524[2];
	double fVec10[1024];
	double fRec544[2];
	double fRec542[2];
	double fRec541[2];
	double fRec539[2];
	double fRec538[2];
	double fRec536[2];
	double fRec535[2];
	double fRec533[2];
	double fRec532[2];
	double fRec530[2];
	double fRec556[2];
	double fRec554[2];
	double fRec553[2];
	double fRec551[2];
	double fRec550[2];
	double fRec548[2];
	double fRec547[2];
	double fRec545[2];
	double fRec565[2];
	double fRec563[2];
	double fRec562[2];
	double fRec560[2];
	double fRec559[2];
	double fRec557[2];
	double fRec568[2];
	double fRec566[2];
	double fRec574[2];
	double fRec572[2];
	double fRec571[2];
	double fRec569[2];
	double fVec11[1024];
	double fRec589[2];
	double fRec587[2];
	double fRec586[2];
	double fRec584[2];
	double fRec583[2];
	double fRec581[2];
	double fRec580[2];
	double fRec578[2];
	double fRec577[2];
	double fRec575[2];
	double fRec601[2];
	double fRec599[2];
	double fRec598[2];
	double fRec596[2];
	double fRec595[2];
	double fRec593[2];
	double fRec592[2];
	double fRec590[2];
	double fRec610[2];
	double fRec608[2];
	double fRec607[2];
	double fRec605[2];
	double fRec604[2];
	double fRec602[2];
	double fRec613[2];
	double fRec611[2];
	double fRec619[2];
	double fRec617[2];
	double fRec616[2];
	double fRec614[2];
	double fVec12[1024];
	double fRec634[2];
	double fRec632[2];
	double fRec631[2];
	double fRec629[2];
	double fRec628[2];
	double fRec626[2];
	double fRec625[2];
	double fRec623[2];
	double fRec622[2];
	double fRec620[2];
	double fRec637[2];
	double fRec635[2];
	double fRec643[2];
	double fRec641[2];
	double fRec640[2];
	double fRec638[2];
	double fRec652[2];
	double fRec650[2];
	double fRec649[2];
	double fRec647[2];
	double fRec646[2];
	double fRec644[2];
	double fRec664[2];
	double fRec662[2];
	double fRec661[2];
	double fRec659[2];
	double fRec658[2];
	double fRec656[2];
	double fRec655[2];
	double fRec653[2];
	double fVec13[1024];
	double fRec667[2];
	double fRec665[2];
	double fRec682[2];
	double fRec680[2];
	double fRec679[2];
	double fRec677[2];
	double fRec676[2];
	double fRec674[2];
	double fRec673[2];
	double fRec671[2];
	double fRec670[2];
	double fRec668[2];
	double fRec688[2];
	double fRec686[2];
	double fRec685[2];
	double fRec683[2];
	double fRec697[2];
	double fRec695[2];
	double fRec694[2];
	double fRec692[2];
	double fRec691[2];
	double fRec689[2];
	double fRec709[2];
	double fRec707[2];
	double fRec706[2];
	double fRec704[2];
	double fRec703[2];
	double fRec701[2];
	double fRec700[2];
	double fRec698[2];
	double fVec14[1024];
	double fRec721[2];
	double fRec719[2];
	double fRec718[2];
	double fRec716[2];
	double fRec715[2];
	double fRec713[2];
	double fRec712[2];
	double fRec710[2];
	double fRec736[2];
	double fRec734[2];
	double fRec733[2];
	double fRec731[2];
	double fRec730[2];
	double fRec728[2];
	double fRec727[2];
	double fRec725[2];
	double fRec724[2];
	double fRec722[2];
	double fRec745[2];
	double fRec743[2];
	double fRec742[2];
	double fRec740[2];
	double fRec739[2];
	double fRec737[2];
	double fRec748[2];
	double fRec746[2];
	double fRec754[2];
	double fRec752[2];
	double fRec751[2];
	double fRec749[2];
	double fVec15[1024];
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fRec760[2];
	double fRec758[2];
	double fRec757[2];
	double fRec755[2];
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec763[2];
	double fRec761[2];
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec778[2];
	double fRec776[2];
	double fRec775[2];
	double fRec773[2];
	double fRec772[2];
	double fRec770[2];
	double fRec769[2];
	double fRec767[2];
	double fRec766[2];
	double fRec764[2];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec787[2];
	double fRec785[2];
	double fRec784[2];
	double fRec782[2];
	double fRec781[2];
	double fRec779[2];
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec799[2];
	double fRec797[2];
	double fRec796[2];
	double fRec794[2];
	double fRec793[2];
	double fRec791[2];
	double fRec790[2];
	double fRec788[2];
	double fVec16[1024];
	int iConst63;
	double fRec811[2];
	double fRec809[2];
	double fRec808[2];
	double fRec806[2];
	double fRec805[2];
	double fRec803[2];
	double fRec802[2];
	double fRec800[2];
	double fRec826[2];
	double fRec824[2];
	double fRec823[2];
	double fRec821[2];
	double fRec820[2];
	double fRec818[2];
	double fRec817[2];
	double fRec815[2];
	double fRec814[2];
	double fRec812[2];
	double fRec832[2];
	double fRec830[2];
	double fRec829[2];
	double fRec827[2];
	double fRec841[2];
	double fRec839[2];
	double fRec838[2];
	double fRec836[2];
	double fRec835[2];
	double fRec833[2];
	double fRec844[2];
	double fRec842[2];
	double fVec17[1024];
	double fRec859[2];
	double fRec857[2];
	double fRec856[2];
	double fRec854[2];
	double fRec853[2];
	double fRec851[2];
	double fRec850[2];
	double fRec848[2];
	double fRec847[2];
	double fRec845[2];
	double fRec871[2];
	double fRec869[2];
	double fRec868[2];
	double fRec866[2];
	double fRec865[2];
	double fRec863[2];
	double fRec862[2];
	double fRec860[2];
	double fRec880[2];
	double fRec878[2];
	double fRec877[2];
	double fRec875[2];
	double fRec874[2];
	double fRec872[2];
	double fRec883[2];
	double fRec881[2];
	double fRec889[2];
	double fRec887[2];
	double fRec886[2];
	double fRec884[2];
	double fVec18[1024];
	double fRec901[2];
	double fRec899[2];
	double fRec898[2];
	double fRec896[2];
	double fRec895[2];
	double fRec893[2];
	double fRec892[2];
	double fRec890[2];
	double fRec910[2];
	double fRec908[2];
	double fRec907[2];
	double fRec905[2];
	double fRec904[2];
	double fRec902[2];
	double fRec916[2];
	double fRec914[2];
	double fRec913[2];
	double fRec911[2];
	double fRec919[2];
	double fRec917[2];
	double fRec934[2];
	double fRec932[2];
	double fRec931[2];
	double fRec929[2];
	double fRec928[2];
	double fRec926[2];
	double fRec925[2];
	double fRec923[2];
	double fRec922[2];
	double fRec920[2];
	double fVec19[1024];
	double fRec949[2];
	double fRec947[2];
	double fRec946[2];
	double fRec944[2];
	double fRec943[2];
	double fRec941[2];
	double fRec940[2];
	double fRec938[2];
	double fRec937[2];
	double fRec935[2];
	double fRec961[2];
	double fRec959[2];
	double fRec958[2];
	double fRec956[2];
	double fRec955[2];
	double fRec953[2];
	double fRec952[2];
	double fRec950[2];
	double fRec967[2];
	double fRec965[2];
	double fRec964[2];
	double fRec962[2];
	double fRec976[2];
	double fRec974[2];
	double fRec973[2];
	double fRec971[2];
	double fRec970[2];
	double fRec968[2];
	double fRec979[2];
	double fRec977[2];
	double fVec20[1024];
	double fRec994[2];
	double fRec992[2];
	double fRec991[2];
	double fRec989[2];
	double fRec988[2];
	double fRec986[2];
	double fRec985[2];
	double fRec983[2];
	double fRec982[2];
	double fRec980[2];
	double fRec1006[2];
	double fRec1004[2];
	double fRec1003[2];
	double fRec1001[2];
	double fRec1000[2];
	double fRec998[2];
	double fRec997[2];
	double fRec995[2];
	double fRec1015[2];
	double fRec1013[2];
	double fRec1012[2];
	double fRec1010[2];
	double fRec1009[2];
	double fRec1007[2];
	double fRec1018[2];
	double fRec1016[2];
	double fRec1024[2];
	double fRec1022[2];
	double fRec1021[2];
	double fRec1019[2];
	double fVec21[1024];
	double fRec1039[2];
	double fRec1037[2];
	double fRec1036[2];
	double fRec1034[2];
	double fRec1033[2];
	double fRec1031[2];
	double fRec1030[2];
	double fRec1028[2];
	double fRec1027[2];
	double fRec1025[2];
	double fRec1042[2];
	double fRec1040[2];
	double fRec1054[2];
	double fRec1052[2];
	double fRec1051[2];
	double fRec1049[2];
	double fRec1048[2];
	double fRec1046[2];
	double fRec1045[2];
	double fRec1043[2];
	double fRec1060[2];
	double fRec1058[2];
	double fRec1057[2];
	double fRec1055[2];
	double fRec1069[2];
	double fRec1067[2];
	double fRec1066[2];
	double fRec1064[2];
	double fRec1063[2];
	double fRec1061[2];
	double fVec22[1024];
	double fRec1078[2];
	double fRec1076[2];
	double fRec1075[2];
	double fRec1073[2];
	double fRec1072[2];
	double fRec1070[2];
	double fRec1081[2];
	double fRec1079[2];
	double fRec1096[2];
	double fRec1094[2];
	double fRec1093[2];
	double fRec1091[2];
	double fRec1090[2];
	double fRec1088[2];
	double fRec1087[2];
	double fRec1085[2];
	double fRec1084[2];
	double fRec1082[2];
	double fRec1102[2];
	double fRec1100[2];
	double fRec1099[2];
	double fRec1097[2];
	double fRec1114[2];
	double fRec1112[2];
	double fRec1111[2];
	double fRec1109[2];
	double fRec1108[2];
	double fRec1106[2];
	double fRec1105[2];
	double fRec1103[2];
	double fVec23[1024];
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fRec1126[2];
	double fRec1124[2];
	double fRec1123[2];
	double fRec1121[2];
	double fRec1120[2];
	double fRec1118[2];
	double fRec1117[2];
	double fRec1115[2];
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec1141[2];
	double fRec1139[2];
	double fRec1138[2];
	double fRec1136[2];
	double fRec1135[2];
	double fRec1133[2];
	double fRec1132[2];
	double fRec1130[2];
	double fRec1129[2];
	double fRec1127[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec1150[2];
	double fRec1148[2];
	double fRec1147[2];
	double fRec1145[2];
	double fRec1144[2];
	double fRec1142[2];
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec1153[2];
	double fRec1151[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec1159[2];
	double fRec1157[2];
	double fRec1156[2];
	double fRec1154[2];
	double fVec24[128];
	int iConst93;
	double fRec1174[2];
	double fRec1172[2];
	double fRec1171[2];
	double fRec1169[2];
	double fRec1168[2];
	double fRec1166[2];
	double fRec1165[2];
	double fRec1163[2];
	double fRec1162[2];
	double fRec1160[2];
	double fRec1183[2];
	double fRec1181[2];
	double fRec1180[2];
	double fRec1178[2];
	double fRec1177[2];
	double fRec1175[2];
	double fRec1189[2];
	double fRec1187[2];
	double fRec1186[2];
	double fRec1184[2];
	double fRec1201[2];
	double fRec1199[2];
	double fRec1198[2];
	double fRec1196[2];
	double fRec1195[2];
	double fRec1193[2];
	double fRec1192[2];
	double fRec1190[2];
	double fRec1204[2];
	double fRec1202[2];
	double fVec25[128];
	double fRec1219[2];
	double fRec1217[2];
	double fRec1216[2];
	double fRec1214[2];
	double fRec1213[2];
	double fRec1211[2];
	double fRec1210[2];
	double fRec1208[2];
	double fRec1207[2];
	double fRec1205[2];
	double fRec1231[2];
	double fRec1229[2];
	double fRec1228[2];
	double fRec1226[2];
	double fRec1225[2];
	double fRec1223[2];
	double fRec1222[2];
	double fRec1220[2];
	double fRec1240[2];
	double fRec1238[2];
	double fRec1237[2];
	double fRec1235[2];
	double fRec1234[2];
	double fRec1232[2];
	double fRec1243[2];
	double fRec1241[2];
	double fRec1249[2];
	double fRec1247[2];
	double fRec1246[2];
	double fRec1244[2];
	double fVec26[128];
	double fRec1264[2];
	double fRec1262[2];
	double fRec1261[2];
	double fRec1259[2];
	double fRec1258[2];
	double fRec1256[2];
	double fRec1255[2];
	double fRec1253[2];
	double fRec1252[2];
	double fRec1250[2];
	double fRec1273[2];
	double fRec1271[2];
	double fRec1270[2];
	double fRec1268[2];
	double fRec1267[2];
	double fRec1265[2];
	double fRec1279[2];
	double fRec1277[2];
	double fRec1276[2];
	double fRec1274[2];
	double fRec1291[2];
	double fRec1289[2];
	double fRec1288[2];
	double fRec1286[2];
	double fRec1285[2];
	double fRec1283[2];
	double fRec1282[2];
	double fRec1280[2];
	double fRec1294[2];
	double fRec1292[2];
	double fVec27[128];
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fRec1309[2];
	double fRec1307[2];
	double fRec1306[2];
	double fRec1304[2];
	double fRec1303[2];
	double fRec1301[2];
	double fRec1300[2];
	double fRec1298[2];
	double fRec1297[2];
	double fRec1295[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec1321[2];
	double fRec1319[2];
	double fRec1318[2];
	double fRec1316[2];
	double fRec1315[2];
	double fRec1313[2];
	double fRec1312[2];
	double fRec1310[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec1330[2];
	double fRec1328[2];
	double fRec1327[2];
	double fRec1325[2];
	double fRec1324[2];
	double fRec1322[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec1333[2];
	double fRec1331[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec1339[2];
	double fRec1337[2];
	double fRec1336[2];
	double fRec1334[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_Dome_5h3v_normal_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_5h3v_normal_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 36;
		
	}
	virtual int getNumOutputs() {
		return 29;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
				rate = 1;
				break;
			}
			case 16: {
				rate = 1;
				break;
			}
			case 17: {
				rate = 1;
				break;
			}
			case 18: {
				rate = 1;
				break;
			}
			case 19: {
				rate = 1;
				break;
			}
			case 20: {
				rate = 0;
				break;
			}
			case 21: {
				rate = 1;
				break;
			}
			case 22: {
				rate = 1;
				break;
			}
			case 23: {
				rate = 1;
				break;
			}
			case 24: {
				rate = 1;
				break;
			}
			case 25: {
				rate = 1;
				break;
			}
			case 26: {
				rate = 1;
				break;
			}
			case 27: {
				rate = 1;
				break;
			}
			case 28: {
				rate = 1;
				break;
			}
			case 29: {
				rate = 0;
				break;
			}
			case 30: {
				rate = 0;
				break;
			}
			case 31: {
				rate = 0;
				break;
			}
			case 32: {
				rate = 1;
				break;
			}
			case 33: {
				rate = 1;
				break;
			}
			case 34: {
				rate = 1;
				break;
			}
			case 35: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
				rate = 1;
				break;
			}
			case 16: {
				rate = 1;
				break;
			}
			case 17: {
				rate = 1;
				break;
			}
			case 18: {
				rate = 1;
				break;
			}
			case 19: {
				rate = 1;
				break;
			}
			case 20: {
				rate = 1;
				break;
			}
			case 21: {
				rate = 1;
				break;
			}
			case 22: {
				rate = 1;
				break;
			}
			case 23: {
				rate = 1;
				break;
			}
			case 24: {
				rate = 1;
				break;
			}
			case 25: {
				rate = 1;
				break;
			}
			case 26: {
				rate = 1;
				break;
			}
			case 27: {
				rate = 1;
				break;
			}
			case 28: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		iConst0 = std::min(192000, std::max(1, fSamplingFreq));
		fConst1 = double(iConst0);
		fConst2 = ((136.75852393116773 / fConst1) + 1.0);
		fConst3 = (0.0 - (273.51704786233546 / (fConst1 * fConst2)));
		fConst4 = mydsp_faustpower2_f(fConst1);
		fConst5 = ((((20072.386056136751 / fConst1) + 251.40744116780635) / fConst1) + 1.0);
		fConst6 = (0.0 - (80289.544224547004 / (fConst4 * fConst5)));
		fConst7 = (0.0 - (((80289.544224547004 / fConst1) + 502.81488233561271) / (fConst1 * fConst5)));
		fConst8 = ((((25534.494160946691 / fConst1) + 174.35800127324134) / fConst1) + 1.0);
		fConst9 = (1.0 / ((fConst2 * fConst5) * fConst8));
		fConst10 = (3.1415926535897931 / double(iConst0));
		fConst11 = (0.0 - (102137.97664378677 / (fConst4 * fConst8)));
		fConst12 = (0.0 - (((102137.97664378677 / fConst1) + 348.71600254648268) / (fConst1 * fConst8)));
		fConst13 = ((37.501597758147724 / fConst1) + 1.0);
		fConst14 = (1.0 / fConst13);
		fConst15 = (0.0 - (75.003195516295449 / (fConst1 * fConst13)));
		fConst16 = ((((12854.404366681647 / fConst1) + 217.22505009970442) / fConst1) + 1.0);
		fConst17 = ((((16156.096054437347 / fConst1) + 157.79092748177277) / fConst1) + 1.0);
		fConst18 = (1.0 / (fConst16 * fConst17));
		fConst19 = (0.0 - (((64624.384217749386 / fConst1) + 315.58185496354554) / (fConst1 * fConst17)));
		fConst20 = (0.0 - (64624.384217749386 / (fConst4 * fConst17)));
		fConst21 = (0.0 - (((51417.617466726588 / fConst1) + 434.45010019940884) / (fConst1 * fConst16)));
		fConst22 = (0.0 - (51417.617466726588 / (fConst4 * fConst16)));
		fConst23 = ((((4219.1095032417315 / fConst1) + 112.50479327444317) / fConst1) + 1.0);
		fConst24 = (1.0 / fConst23);
		fConst25 = (0.0 - (16876.438012966926 / (fConst4 * fConst23)));
		fConst26 = (0.0 - (((16876.438012966926 / fConst1) + 225.00958654888635) / (fConst1 * fConst23)));
		fConst27 = ((87.085661089049111 / fConst1) + 1.0);
		fConst28 = (0.0 - (174.17132217809822 / (fConst1 * fConst27)));
		fConst29 = ((((9084.3512875420056 / fConst1) + 137.92392545983725) / fConst1) + 1.0);
		fConst30 = (1.0 / (fConst27 * fConst29));
		fConst31 = (0.0 - (36337.405150168022 / (fConst4 * fConst29)));
		fConst32 = (0.0 - (((36337.405150168022 / fConst1) + 275.8478509196745) / (fConst1 * fConst29)));
		iConst33 = int(((0.00279416999341243 * double(iConst0)) + 0.5));
		fConst34 = ((((5636.6598195633251 / fConst1) + 130.03837686886888) / fConst1) + 1.0);
		fConst35 = (1.0 / fConst34);
		fConst36 = (0.0 - (22546.6392782533 / (fConst4 * fConst34)));
		fConst37 = (0.0 - (((22546.6392782533 / fConst1) + 260.07675373773776) / (fConst1 * fConst34)));
		fConst38 = ((43.346125622956293 / fConst1) + 1.0);
		fConst39 = (1.0 / fConst38);
		fConst40 = (0.0 - (86.692251245912587 / (fConst1 * fConst38)));
		fConst41 = ((158.07198926724513 / fConst1) + 1.0);
		fConst42 = (0.0 - (316.14397853449026 / (fConst1 * fConst41)));
		fConst43 = ((((26816.372478234491 / fConst1) + 290.58864632075819) / fConst1) + 1.0);
		fConst44 = (0.0 - (107265.48991293796 / (fConst4 * fConst43)));
		fConst45 = (0.0 - (((107265.48991293796 / fConst1) + 581.17729264151637) / (fConst1 * fConst43)));
		fConst46 = ((((34113.657666219668 / fConst1) + 201.53124875634055) / fConst1) + 1.0);
		fConst47 = (1.0 / ((fConst41 * fConst43) * fConst46));
		fConst48 = (0.0 - (136454.63066487867 / (fConst4 * fConst46)));
		fConst49 = (0.0 - (((136454.63066487867 / fConst1) + 403.06249751268109) / (fConst1 * fConst46)));
		fConst50 = ((100.65773810141164 / fConst1) + 1.0);
		fConst51 = (0.0 - (201.31547620282328 / (fConst1 * fConst50)));
		fConst52 = ((((12136.541573510469 / fConst1) + 159.41901563632612) / fConst1) + 1.0);
		fConst53 = (1.0 / (fConst50 * fConst52));
		fConst54 = (0.0 - (48546.166294041876 / (fConst4 * fConst52)));
		fConst55 = (0.0 - (((48546.166294041876 / fConst1) + 318.83803127265224) / (fConst1 * fConst52)));
		fConst56 = ((((17173.269511593062 / fConst1) + 251.07901724077982) / fConst1) + 1.0);
		fConst57 = (0.0 - (68693.078046372248 / (fConst4 * fConst56)));
		fConst58 = (0.0 - (((68693.078046372248 / fConst1) + 502.15803448155964) / (fConst1 * fConst56)));
		fConst59 = ((((21584.274454380036 / fConst1) + 182.38223898878306) / fConst1) + 1.0);
		fConst60 = (1.0 / (fConst56 * fConst59));
		fConst61 = (0.0 - (86337.097817520145 / (fConst4 * fConst59)));
		fConst62 = (0.0 - (((86337.097817520145 / fConst1) + 364.76447797756612) / (fConst1 * fConst59)));
		iConst63 = int(((0.0045918789464212588 * double(iConst0)) + 0.5));
		fConst64 = ((((9506.8681619800409 / fConst1) + 186.81109363958794) / fConst1) + 1.0);
		fConst65 = (0.0 - (38027.472647920164 / (fConst4 * fConst64)));
		fConst66 = (0.0 - (((38027.472647920164 / fConst1) + 373.62218727917588) / (fConst1 * fConst64)));
		fConst67 = ((((11948.735298846983 / fConst1) + 135.69841837184595) / fConst1) + 1.0);
		fConst68 = (1.0 / (fConst64 * fConst67));
		fConst69 = (0.0 - (47794.941195387932 / (fConst4 * fConst67)));
		fConst70 = (0.0 - (((47794.941195387932 / fConst1) + 271.39683674369189) / (fConst1 * fConst67)));
		fConst71 = ((117.61078848130494 / fConst1) + 1.0);
		fConst72 = (0.0 - (235.22157696260987 / (fConst1 * fConst71)));
		fConst73 = ((((14845.147428742359 / fConst1) + 216.20756451491863) / fConst1) + 1.0);
		fConst74 = (0.0 - (59380.589714969436 / (fConst4 * fConst73)));
		fConst75 = (0.0 - (((59380.589714969436 / fConst1) + 432.41512902983726) / (fConst1 * fConst73)));
		fConst76 = ((((18884.816646983691 / fConst1) + 149.94591502092698) / fConst1) + 1.0);
		fConst77 = (1.0 / ((fConst71 * fConst73) * fConst76));
		fConst78 = (0.0 - (75539.266587934762 / (fConst4 * fConst76)));
		fConst79 = (0.0 - (((75539.266587934762 / fConst1) + 299.89183004185395) / (fConst1 * fConst76)));
		fConst80 = ((74.892686552055764 / fConst1) + 1.0);
		fConst81 = (0.0 - (149.78537310411153 / (fConst1 * fConst80)));
		fConst82 = ((((6718.6100237851942 / fConst1) + 118.6130206548046) / fConst1) + 1.0);
		fConst83 = (1.0 / (fConst80 * fConst82));
		fConst84 = (0.0 - (26874.440095140777 / (fConst4 * fConst82)));
		fConst85 = (0.0 - (((26874.440095140777 / fConst1) + 237.2260413096092) / (fConst1 * fConst82)));
		fConst86 = ((32.250951201143394 / fConst1) + 1.0);
		fConst87 = (1.0 / fConst86);
		fConst88 = (0.0 - (64.501902402286788 / (fConst86 * fConst1)));
		fConst89 = ((((3120.3715601355971 / fConst1) + 96.752853603430182) / fConst1) + 1.0);
		fConst90 = (1.0 / fConst89);
		fConst91 = (0.0 - (12481.486240542388 / (fConst4 * fConst89)));
		fConst92 = (0.0 - (((12481.486240542388 / fConst1) + 193.50570720686036) / (fConst1 * fConst89)));
		iConst93 = int(((0.00062351655744552741 * double(iConst0)) + 0.5));
		fConst94 = ((113.06359629792655 / fConst1) + 1.0);
		fConst95 = (0.0 - (226.1271925958531 / (fConst1 * fConst94)));
		fConst96 = ((((13719.420973080949 / fConst1) + 207.84831992482057) / fConst1) + 1.0);
		fConst97 = (0.0 - (54877.683892323796 / (fConst4 * fConst96)));
		fConst98 = (0.0 - (((54877.683892323796 / fConst1) + 415.69663984964114) / (fConst1 * fConst96)));
		fConst99 = ((((17452.756924312038 / fConst1) + 144.14854811677549) / fConst1) + 1.0);
		fConst100 = (1.0 / ((fConst94 * fConst96) * fConst99));
		fConst101 = (0.0 - (69811.027697248152 / (fConst4 * fConst99)));
		fConst102 = (0.0 - (((69811.027697248152 / fConst1) + 288.29709623355097) / (fConst1 * fConst99)));
		fConst103 = ((((8785.9502289115408 / fConst1) + 179.58840636969236) / fConst1) + 1.0);
		fConst104 = (0.0 - (35143.800915646163 / (fConst4 * fConst103)));
		fConst105 = (0.0 - (((35143.800915646163 / fConst1) + 359.17681273938473) / (fConst1 * fConst103)));
		fConst106 = ((((11042.647467643346 / fConst1) + 130.45190318998954) / fConst1) + 1.0);
		fConst107 = (1.0 / (fConst106 * fConst103));
		fConst108 = (0.0 - (44170.589870573385 / (fConst106 * fConst4)));
		fConst109 = (0.0 - (((44170.589870573385 / fConst1) + 260.90380637997907) / (fConst106 * fConst1)));
		fConst110 = ((71.997106620323152 / fConst1) + 1.0);
		fConst111 = (0.0 - (143.9942132406463 / (fConst1 * fConst110)));
		fConst112 = ((((6209.1292600978468 / fConst1) + 114.02707911548603) / fConst1) + 1.0);
		fConst113 = (1.0 / (fConst110 * fConst112));
		fConst114 = (0.0 - (24836.517040391387 / (fConst4 * fConst112)));
		fConst115 = (0.0 - (((24836.517040391387 / fConst1) + 228.05415823097206) / (fConst1 * fConst112)));
		fConst116 = ((31.004030955968197 / fConst1) + 1.0);
		fConst117 = (1.0 / fConst116);
		fConst118 = (0.0 - (62.008061911936394 / (fConst1 * fConst116)));
		fConst119 = ((((2883.749806555903 / fConst1) + 93.012092867904585) / fConst1) + 1.0);
		fConst120 = (1.0 / fConst119);
		fConst121 = (0.0 - (11534.999226223612 / (fConst4 * fConst119)));
		fConst122 = (0.0 - (((11534.999226223612 / fConst1) + 186.02418573580917) / (fConst1 * fConst119)));
		
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0);
		fHslider0 = FAUSTFLOAT(-10.0);
		fHslider1 = FAUSTFLOAT(400.0);
		fHslider2 = FAUSTFLOAT(0.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec17[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec16[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec18[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec19[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec20[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec21[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec22[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec23[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec24[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec25[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec15[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec10[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec9[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec7[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec6[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec4[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec3[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec1[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec29[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec30[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec31[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec28[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec26[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec44[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec45[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec46[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec47[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec48[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec49[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec50[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec51[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec43[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec41[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec40[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec38[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec37[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec35[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec34[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec32[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec58[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec59[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec60[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec61[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec62[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec57[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec55[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec54[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec52[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec72[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec73[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec74[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec75[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec76[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec77[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec78[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec71[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec69[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec68[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec66[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec65[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec63[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec79[l64] = 0.0;
			
		}
		IOTA = 0;
		for (int l65 = 0; (l65 < 1024); l65 = (l65 + 1)) {
			fVec0[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec91[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec89[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec88[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec86[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec85[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec83[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec82[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec80[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec100[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec98[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec97[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec95[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec94[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec92[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec106[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec104[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec103[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec101[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec121[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec119[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec118[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec116[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec115[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec113[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec112[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec110[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec109[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec107[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec124[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec122[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 1024); l96 = (l96 + 1)) {
			fVec1[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec139[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec137[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec136[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec134[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec133[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec131[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec130[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec128[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec127[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec125[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec151[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec149[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec148[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec146[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec145[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec143[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec142[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec140[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec160[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec158[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec157[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec155[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec154[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec152[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec163[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec161[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec169[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec167[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec166[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec164[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 1024); l127 = (l127 + 1)) {
			fVec2[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec175[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec173[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec172[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec170[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec178[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec176[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec193[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec191[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec190[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec188[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec187[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec185[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec184[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec182[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec181[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec179[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec202[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec200[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec199[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec197[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec196[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec194[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec214[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec212[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec211[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec209[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec208[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec206[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec205[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec203[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 1024); l158 = (l158 + 1)) {
			fVec3[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec229[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec227[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec226[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec224[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec223[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec221[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec220[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec218[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec217[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec215[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec241[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec239[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec238[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec236[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec235[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec233[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec232[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec230[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec250[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec248[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec247[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec245[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec244[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec242[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec253[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec251[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec259[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec257[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec256[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec254[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 1024); l189 = (l189 + 1)) {
			fVec4[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec274[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec272[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec271[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec269[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec268[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec266[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec265[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec263[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec262[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec260[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec286[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec284[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec283[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec281[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec280[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec278[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec277[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec275[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec295[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec293[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec292[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec290[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec289[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec287[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec298[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec296[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec304[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec302[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec301[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec299[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 1024); l220 = (l220 + 1)) {
			fVec5[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec319[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec317[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec316[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec314[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec313[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec311[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec310[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec308[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec307[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec305[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec328[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec326[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec325[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec323[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec322[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec320[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec331[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec329[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec337[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec335[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec334[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec332[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec349[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec347[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec346[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec344[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec343[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec341[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec340[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec338[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 1024); l251 = (l251 + 1)) {
			fVec6[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec358[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec356[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec355[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec353[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec352[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec350[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec364[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec362[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec361[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec359[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec367[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec365[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec379[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec377[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec376[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec374[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec373[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec371[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec370[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec368[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec394[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec392[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec391[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec389[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec388[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec386[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec385[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec383[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec382[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec380[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 1024); l282 = (l282 + 1)) {
			fVec7[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec409[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec407[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec406[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec404[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec403[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec401[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec400[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec398[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec397[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec395[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec421[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec419[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec418[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec416[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec415[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec413[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec412[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec410[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec430[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec428[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec427[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec425[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec424[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec422[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec433[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec431[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec439[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec437[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec436[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec434[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 1024); l313 = (l313 + 1)) {
			fVec8[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec454[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec452[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec451[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec449[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec448[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec446[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec445[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec443[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec442[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec440[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec457[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec455[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec463[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec461[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec460[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec458[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec472[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec470[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec469[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec467[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec466[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec464[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec484[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec482[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec481[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec479[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec478[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec476[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec475[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec473[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 1024); l344 = (l344 + 1)) {
			fVec9[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec499[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec497[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec496[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec494[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec493[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec491[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec490[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec488[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec487[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec485[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec511[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec509[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec508[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec506[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec505[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec503[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec502[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec500[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec520[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec518[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec517[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec515[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec514[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec512[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec523[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec521[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec529[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec527[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec526[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec524[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 1024); l375 = (l375 + 1)) {
			fVec10[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec544[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec542[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec541[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec539[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec538[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec536[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec535[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec533[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec532[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec530[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec556[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec554[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec553[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec551[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec550[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec548[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec547[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec545[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec565[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec563[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec562[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec560[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec559[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec557[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec568[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec566[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec574[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec572[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec571[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec569[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 1024); l406 = (l406 + 1)) {
			fVec11[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec589[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec587[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec586[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec584[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec583[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec581[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec580[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec578[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec577[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec575[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec601[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec599[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec598[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec596[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec595[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec593[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec592[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec590[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec610[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec608[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec607[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec605[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec604[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec602[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec613[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec611[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec619[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec617[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec616[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec614[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 1024); l437 = (l437 + 1)) {
			fVec12[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec634[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec632[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec631[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec629[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec628[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec626[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec625[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec623[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec622[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec620[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec637[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec635[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec643[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec641[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec640[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec638[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec652[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec650[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec649[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec647[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec646[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec644[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec664[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec662[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec661[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec659[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec658[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec656[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec655[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec653[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 1024); l468 = (l468 + 1)) {
			fVec13[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec667[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec665[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec682[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec680[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec679[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec677[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec676[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec674[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec673[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec671[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec670[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec668[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec688[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec686[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec685[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec683[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec697[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec695[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec694[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec692[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec691[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec689[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec709[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec707[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec706[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec704[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec703[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec701[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec700[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec698[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 1024); l499 = (l499 + 1)) {
			fVec14[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec721[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec719[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec718[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec716[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec715[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec713[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec712[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec710[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec736[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec734[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec733[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec731[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec730[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec728[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec727[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec725[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec724[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec722[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec745[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec743[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec742[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec740[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec739[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec737[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec748[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec746[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec754[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec752[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec751[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec749[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 1024); l530 = (l530 + 1)) {
			fVec15[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec760[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec758[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec757[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec755[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec763[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec761[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec778[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec776[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec775[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec773[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec772[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec770[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec769[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec767[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec766[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec764[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec787[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec785[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec784[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec782[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec781[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec779[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec799[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec797[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec796[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec794[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec793[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec791[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec790[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec788[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 1024); l561 = (l561 + 1)) {
			fVec16[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec811[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec809[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec808[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec806[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec805[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec803[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec802[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec800[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec826[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec824[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec823[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec821[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec820[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec818[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec817[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec815[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec814[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec812[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec832[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec830[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec829[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec827[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec841[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec839[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec838[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec836[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec835[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec833[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec844[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec842[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 1024); l592 = (l592 + 1)) {
			fVec17[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec859[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec857[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec856[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec854[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec853[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec851[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec850[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec848[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec847[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec845[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec871[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec869[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec868[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec866[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec865[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec863[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec862[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec860[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec880[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec878[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec877[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec875[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec874[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec872[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec883[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec881[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec889[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec887[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec886[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec884[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 1024); l623 = (l623 + 1)) {
			fVec18[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec901[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec899[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec898[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec896[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec895[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec893[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec892[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec890[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec910[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec908[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec907[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec905[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec904[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec902[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec916[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec914[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec913[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec911[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec919[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec917[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec934[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec932[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec931[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec929[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec928[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec926[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec925[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec923[l651] = 0.0;
			
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec922[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec920[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 1024); l654 = (l654 + 1)) {
			fVec19[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec949[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec947[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec946[l657] = 0.0;
			
		}
		for (int l658 = 0; (l658 < 2); l658 = (l658 + 1)) {
			fRec944[l658] = 0.0;
			
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec943[l659] = 0.0;
			
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec941[l660] = 0.0;
			
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec940[l661] = 0.0;
			
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec938[l662] = 0.0;
			
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec937[l663] = 0.0;
			
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec935[l664] = 0.0;
			
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec961[l665] = 0.0;
			
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec959[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec958[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 2); l668 = (l668 + 1)) {
			fRec956[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec955[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec953[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec952[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec950[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec967[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec965[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec964[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 2); l676 = (l676 + 1)) {
			fRec962[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec976[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec974[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec973[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec971[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec970[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec968[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec979[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec977[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 1024); l685 = (l685 + 1)) {
			fVec20[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec994[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec992[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec991[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec989[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec988[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec986[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec985[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec983[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec982[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec980[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec1006[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 2); l697 = (l697 + 1)) {
			fRec1004[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec1003[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec1001[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec1000[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec998[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec997[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec995[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec1015[l704] = 0.0;
			
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec1013[l705] = 0.0;
			
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1012[l706] = 0.0;
			
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec1010[l707] = 0.0;
			
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec1009[l708] = 0.0;
			
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1007[l709] = 0.0;
			
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1018[l710] = 0.0;
			
		}
		for (int l711 = 0; (l711 < 2); l711 = (l711 + 1)) {
			fRec1016[l711] = 0.0;
			
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1024[l712] = 0.0;
			
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1022[l713] = 0.0;
			
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1021[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1019[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 1024); l716 = (l716 + 1)) {
			fVec21[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1039[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 2); l718 = (l718 + 1)) {
			fRec1037[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1036[l719] = 0.0;
			
		}
		for (int l720 = 0; (l720 < 2); l720 = (l720 + 1)) {
			fRec1034[l720] = 0.0;
			
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1033[l721] = 0.0;
			
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1031[l722] = 0.0;
			
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1030[l723] = 0.0;
			
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1028[l724] = 0.0;
			
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1027[l725] = 0.0;
			
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1025[l726] = 0.0;
			
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1042[l727] = 0.0;
			
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1040[l728] = 0.0;
			
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1054[l729] = 0.0;
			
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1052[l730] = 0.0;
			
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1051[l731] = 0.0;
			
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1049[l732] = 0.0;
			
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1048[l733] = 0.0;
			
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1046[l734] = 0.0;
			
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1045[l735] = 0.0;
			
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1043[l736] = 0.0;
			
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1060[l737] = 0.0;
			
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1058[l738] = 0.0;
			
		}
		for (int l739 = 0; (l739 < 2); l739 = (l739 + 1)) {
			fRec1057[l739] = 0.0;
			
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1055[l740] = 0.0;
			
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1069[l741] = 0.0;
			
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1067[l742] = 0.0;
			
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1066[l743] = 0.0;
			
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1064[l744] = 0.0;
			
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1063[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1061[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 1024); l747 = (l747 + 1)) {
			fVec22[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1078[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1076[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1075[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1073[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1072[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1070[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1081[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1079[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1096[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1094[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1093[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1091[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 2); l760 = (l760 + 1)) {
			fRec1090[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1088[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1087[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1085[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1084[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1082[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1102[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1100[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1099[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1097[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1114[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1112[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1111[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1109[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1108[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1106[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1105[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1103[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 1024); l778 = (l778 + 1)) {
			fVec23[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1126[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1124[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1123[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 2); l782 = (l782 + 1)) {
			fRec1121[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1120[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1118[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1117[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1115[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1141[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1139[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1138[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1136[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1135[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1133[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1132[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1130[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1129[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1127[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1150[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1148[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1147[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1145[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1144[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1142[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1153[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1151[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1159[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1157[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1156[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1154[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 128); l809 = (l809 + 1)) {
			fVec24[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1174[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1172[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1171[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1169[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1168[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1166[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1165[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1163[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1162[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1160[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1183[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1181[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1180[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1178[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1177[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1175[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1189[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1187[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1186[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1184[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1201[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1199[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1198[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1196[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1195[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1193[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1192[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1190[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1204[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1202[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 128); l840 = (l840 + 1)) {
			fVec25[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1219[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1217[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1216[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 2); l844 = (l844 + 1)) {
			fRec1214[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1213[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1211[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1210[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1208[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1207[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1205[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1231[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1229[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1228[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1226[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1225[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1223[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1222[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1220[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1240[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1238[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1237[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1235[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1234[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1232[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 2); l865 = (l865 + 1)) {
			fRec1243[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1241[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1249[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1247[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1246[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1244[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 128); l871 = (l871 + 1)) {
			fVec26[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1264[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1262[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1261[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1259[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1258[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1256[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1255[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1253[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1252[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1250[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1273[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 2); l883 = (l883 + 1)) {
			fRec1271[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1270[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1268[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 2); l886 = (l886 + 1)) {
			fRec1267[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1265[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1279[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1277[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1276[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1274[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1291[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1289[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1288[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1286[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1285[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1283[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1282[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1280[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1294[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1292[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 128); l902 = (l902 + 1)) {
			fVec27[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1309[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1307[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1306[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1304[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 2); l907 = (l907 + 1)) {
			fRec1303[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1301[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1300[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1298[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1297[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1295[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1321[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1319[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1318[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1316[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1315[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1313[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1312[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1310[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1330[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1328[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1327[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1325[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1324[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1322[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1333[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1331[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1339[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1337[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1336[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1334[l932] = 0.0;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KMHLS_Dome_5h3v_normal_6");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("gain", &fHslider0, -10.0, -30.0, 10.0, 1.0);
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("lf/hf", &fHslider2, 0.0, -3.0, 3.0, 0.10000000000000001);
		ui_interface->addCheckButton("mute", &fCheckbox0);
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("xover", &fHslider1, 400.0, 200.0, 800.0, 20.0);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* input2 = inputs[2];
		FAUSTFLOAT* input3 = inputs[3];
		FAUSTFLOAT* input4 = inputs[4];
		FAUSTFLOAT* input5 = inputs[5];
		FAUSTFLOAT* input6 = inputs[6];
		FAUSTFLOAT* input7 = inputs[7];
		FAUSTFLOAT* input8 = inputs[8];
		FAUSTFLOAT* input9 = inputs[9];
		FAUSTFLOAT* input10 = inputs[10];
		FAUSTFLOAT* input11 = inputs[11];
		FAUSTFLOAT* input12 = inputs[12];
		FAUSTFLOAT* input13 = inputs[13];
		FAUSTFLOAT* input14 = inputs[14];
		FAUSTFLOAT* input15 = inputs[15];
		FAUSTFLOAT* input16 = inputs[16];
		FAUSTFLOAT* input17 = inputs[17];
		FAUSTFLOAT* input18 = inputs[18];
		FAUSTFLOAT* input19 = inputs[19];
		FAUSTFLOAT* input20 = inputs[20];
		FAUSTFLOAT* input21 = inputs[21];
		FAUSTFLOAT* input22 = inputs[22];
		FAUSTFLOAT* input23 = inputs[23];
		FAUSTFLOAT* input24 = inputs[24];
		FAUSTFLOAT* input25 = inputs[25];
		FAUSTFLOAT* input26 = inputs[26];
		FAUSTFLOAT* input27 = inputs[27];
		FAUSTFLOAT* input28 = inputs[28];
		FAUSTFLOAT* input29 = inputs[29];
		FAUSTFLOAT* input30 = inputs[30];
		FAUSTFLOAT* input31 = inputs[31];
		FAUSTFLOAT* input32 = inputs[32];
		FAUSTFLOAT* input33 = inputs[33];
		FAUSTFLOAT* input34 = inputs[34];
		FAUSTFLOAT* input35 = inputs[35];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		FAUSTFLOAT* output8 = outputs[8];
		FAUSTFLOAT* output9 = outputs[9];
		FAUSTFLOAT* output10 = outputs[10];
		FAUSTFLOAT* output11 = outputs[11];
		FAUSTFLOAT* output12 = outputs[12];
		FAUSTFLOAT* output13 = outputs[13];
		FAUSTFLOAT* output14 = outputs[14];
		FAUSTFLOAT* output15 = outputs[15];
		FAUSTFLOAT* output16 = outputs[16];
		FAUSTFLOAT* output17 = outputs[17];
		FAUSTFLOAT* output18 = outputs[18];
		FAUSTFLOAT* output19 = outputs[19];
		FAUSTFLOAT* output20 = outputs[20];
		FAUSTFLOAT* output21 = outputs[21];
		FAUSTFLOAT* output22 = outputs[22];
		FAUSTFLOAT* output23 = outputs[23];
		FAUSTFLOAT* output24 = outputs[24];
		FAUSTFLOAT* output25 = outputs[25];
		FAUSTFLOAT* output26 = outputs[26];
		FAUSTFLOAT* output27 = outputs[27];
		FAUSTFLOAT* output28 = outputs[28];
		double fSlow0 = (0.0010000000000000009 * (double((double(fCheckbox0) < 0.5)) * std::pow(10.0, (0.050000000000000003 * double(fHslider0)))));
		double fSlow1 = (0.0010000000000000009 * double(fHslider1));
		double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider2))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
			double fTemp0 = (fConst3 * fRec1[1]);
			double fTemp1 = (fConst6 * fRec4[1]);
			double fTemp2 = (fConst7 * fRec7[1]);
			fRec17[0] = (fSlow1 + (0.999 * fRec17[1]));
			double fTemp3 = std::tan((fConst10 * fRec17[0]));
			double fTemp4 = ((fTemp3 * (fTemp3 + -2.0)) + 1.0);
			double fTemp5 = mydsp_faustpower2_f(fTemp3);
			double fTemp6 = (fTemp5 + -1.0);
			double fTemp7 = ((fTemp3 * (fTemp3 + 2.0)) + 1.0);
			fRec16[0] = (double(input28[i]) - (((fRec16[2] * fTemp4) + (2.0 * (fRec16[1] * fTemp6))) / fTemp7));
			fRec18[0] = (fSlow2 + (0.999 * fRec18[1]));
			double fTemp8 = (fRec18[0] * fTemp7);
			double fTemp9 = (0.0 - (2.0 / fTemp7));
			double fTemp10 = ((((fRec16[2] + (fRec16[0] + (2.0 * fRec16[1]))) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec16[1] * fTemp9) + ((fRec16[0] + fRec16[2]) / fTemp7))))));
			fRec19[0] = (double(input34[i]) - (((fRec19[2] * fTemp4) + (2.0 * (fRec19[1] * fTemp6))) / fTemp7));
			double fTemp11 = ((0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec19[1] * fTemp9) + ((fRec19[0] + fRec19[2]) / fTemp7))))) + (((fRec19[2] + (fRec19[0] + (2.0 * fRec19[1]))) * fTemp5) / fTemp8));
			fRec20[0] = (double(input25[i]) - (((fRec20[2] * fTemp4) + (2.0 * (fRec20[1] * fTemp6))) / fTemp7));
			double fTemp12 = ((((fRec20[2] + (fRec20[0] + (2.0 * fRec20[1]))) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec20[1] * fTemp9) + ((fRec20[0] + fRec20[2]) / fTemp7))))));
			fRec21[0] = (double(input32[i]) - (((fRec21[2] * fTemp4) + (2.0 * (fRec21[1] * fTemp6))) / fTemp7));
			double fTemp13 = ((((fRec21[2] + (fRec21[0] + (2.0 * fRec21[1]))) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec21[1] * fTemp9) + ((fRec21[0] + fRec21[2]) / fTemp7))))));
			fRec22[0] = (double(input33[i]) - (((fRec22[2] * fTemp4) + (2.0 * (fRec22[1] * fTemp6))) / fTemp7));
			double fTemp14 = ((((fRec22[2] + (fRec22[0] + (2.0 * fRec22[1]))) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec22[1] * fTemp9) + ((fRec22[0] + fRec22[2]) / fTemp7))))));
			fRec23[0] = (double(input27[i]) - (((fRec23[2] * fTemp4) + (2.0 * (fRec23[1] * fTemp6))) / fTemp7));
			double fTemp15 = ((((fRec23[2] + (fRec23[0] + (2.0 * fRec23[1]))) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec23[1] * fTemp9) + ((fRec23[0] + fRec23[2]) / fTemp7))))));
			fRec24[0] = (double(input26[i]) - (((fRec24[2] * fTemp4) + (2.0 * (fRec24[1] * fTemp6))) / fTemp7));
			double fTemp16 = ((((fRec24[2] + (fRec24[0] + (2.0 * fRec24[1]))) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec24[1] * fTemp9) + ((fRec24[0] + fRec24[2]) / fTemp7))))));
			fRec25[0] = (double(input35[i]) - (((fRec25[2] * fTemp4) + (2.0 * (fRec25[1] * fTemp6))) / fTemp7));
			double fTemp17 = ((((fRec25[2] + ((2.0 * fRec25[1]) + fRec25[0])) * fTemp5) / fTemp8) + (0.32855163009999999 * (fRec18[0] * (0.0 - ((fRec25[1] * fTemp9) + ((fRec25[2] + fRec25[0]) / fTemp7))))));
			double fTemp18 = (fConst9 * (((33199174740000.0 * fTemp10) + ((((222111982200000.0 * fTemp11) + (25529231540000.0 * fTemp12)) + (72003189490000.0 * fTemp13)) + (87237143990000.0 * fTemp14))) - (((26393421300000.0 * fTemp15) + (20713953630000.0 * fTemp16)) + (52463066440000.0 * fTemp17))));
			double fTemp19 = (fConst11 * fRec10[1]);
			double fTemp20 = (fConst12 * fRec13[1]);
			fRec15[0] = (fTemp18 + (fTemp19 + (fRec15[1] + fTemp20)));
			fRec13[0] = fRec15[0];
			double fRec14 = ((fTemp20 + fTemp19) + fTemp18);
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			fRec9[0] = (fTemp1 + (fTemp2 + (fRec11 + fRec9[1])));
			fRec7[0] = fRec9[0];
			double fRec8 = (fTemp1 + (fRec11 + fTemp2));
			fRec6[0] = (fRec7[0] + fRec6[1]);
			fRec4[0] = fRec6[0];
			double fRec5 = fRec8;
			fRec3[0] = (fTemp0 + (fRec5 + fRec3[1]));
			fRec1[0] = fRec3[0];
			double fRec2 = (fRec5 + fTemp0);
			fRec29[0] = (double(input2[i]) - (((fTemp4 * fRec29[2]) + (2.0 * (fTemp6 * fRec29[1]))) / fTemp7));
			double fTemp21 = (((fTemp5 * (fRec29[2] + (fRec29[0] + (2.0 * fRec29[1])))) / fTemp8) + (1.4892855819999999 * (fRec18[0] * (0.0 - ((fTemp9 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp7))))));
			fRec30[0] = (double(input3[i]) - (((fTemp4 * fRec30[2]) + (2.0 * (fTemp6 * fRec30[1]))) / fTemp7));
			double fTemp22 = (((fTemp5 * (fRec30[2] + (fRec30[0] + (2.0 * fRec30[1])))) / fTemp8) + (1.4892855819999999 * (fRec18[0] * (0.0 - ((fTemp9 * fRec30[1]) + ((fRec30[0] + fRec30[2]) / fTemp7))))));
			fRec31[0] = (double(input1[i]) - (((fTemp4 * fRec31[2]) + (2.0 * (fTemp6 * fRec31[1]))) / fTemp7));
			double fTemp23 = (((fTemp5 * (fRec31[2] + (fRec31[0] + (2.0 * fRec31[1])))) / fTemp8) + (1.4892855819999999 * (fRec18[0] * (0.0 - ((fTemp9 * fRec31[1]) + ((fRec31[0] + fRec31[2]) / fTemp7))))));
			double fTemp24 = (fConst14 * (((89800884980000.0 * fTemp21) + (194791650500000.0 * fTemp22)) - (42893149520000.0 * fTemp23)));
			double fTemp25 = (fConst15 * fRec26[1]);
			fRec28[0] = (fTemp24 + (fRec28[1] + fTemp25));
			fRec26[0] = fRec28[0];
			double fRec27 = (fTemp25 + fTemp24);
			fRec44[0] = (double(input19[i]) - (((fRec44[2] * fTemp4) + (2.0 * (fRec44[1] * fTemp6))) / fTemp7));
			double fTemp26 = ((((fRec44[2] + (fRec44[0] + (2.0 * fRec44[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec44[1] * fTemp9) + ((fRec44[0] + fRec44[2]) / fTemp7))))));
			fRec45[0] = (double(input16[i]) - (((fRec45[2] * fTemp4) + (2.0 * (fRec45[1] * fTemp6))) / fTemp7));
			double fTemp27 = ((((fRec45[2] + (fRec45[0] + (2.0 * fRec45[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec45[1] * fTemp9) + ((fRec45[0] + fRec45[2]) / fTemp7))))));
			fRec46[0] = (double(input21[i]) - (((fRec46[2] * fTemp4) + (2.0 * (fRec46[1] * fTemp6))) / fTemp7));
			double fTemp28 = ((((fRec46[2] + (fRec46[0] + (2.0 * fRec46[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec46[1] * fTemp9) + ((fRec46[0] + fRec46[2]) / fTemp7))))));
			fRec47[0] = (double(input22[i]) - (((fRec47[2] * fTemp4) + (2.0 * (fRec47[1] * fTemp6))) / fTemp7));
			double fTemp29 = ((((fRec47[2] + (fRec47[0] + (2.0 * fRec47[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec47[1] * fTemp9) + ((fRec47[0] + fRec47[2]) / fTemp7))))));
			fRec48[0] = (double(input23[i]) - (((fRec48[2] * fTemp4) + (2.0 * (fRec48[1] * fTemp6))) / fTemp7));
			double fTemp30 = ((((fRec48[2] + (fRec48[0] + (2.0 * fRec48[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec48[1] * fTemp9) + ((fRec48[0] + fRec48[2]) / fTemp7))))));
			fRec49[0] = (double(input24[i]) - (((fRec49[2] * fTemp4) + (2.0 * (fRec49[1] * fTemp6))) / fTemp7));
			double fTemp31 = ((((fRec49[2] + (fRec49[0] + (2.0 * fRec49[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec49[1] * fTemp9) + ((fRec49[0] + fRec49[2]) / fTemp7))))));
			fRec50[0] = (double(input17[i]) - (((fRec50[2] * fTemp4) + (2.0 * (fRec50[1] * fTemp6))) / fTemp7));
			double fTemp32 = (((((fRec50[0] + (2.0 * fRec50[1])) + fRec50[2]) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec50[1] * fTemp9) + ((fRec50[0] + fRec50[2]) / fTemp7))))));
			fRec51[0] = (double(input18[i]) - (((fRec51[2] * fTemp4) + (2.0 * (fRec51[1] * fTemp6))) / fTemp7));
			double fTemp33 = ((((fRec51[2] + (fRec51[0] + (2.0 * fRec51[1]))) * fTemp5) / fTemp8) + (0.67400163359999998 * (fRec18[0] * (0.0 - ((fRec51[1] * fTemp9) + ((fRec51[0] + fRec51[2]) / fTemp7))))));
			double fTemp34 = (fConst18 * (((19713989250000.0 * fTemp26) + (58572631460000.0 * fTemp27)) - ((((((65771867720000.0 * fTemp28) + (32601335180000.0 * fTemp29)) + (86453598350000.0 * fTemp30)) + (142692743700000.0 * fTemp31)) + (43922174330000.0 * fTemp32)) + (102502769900000.0 * fTemp33))));
			double fTemp35 = (fConst19 * fRec41[1]);
			double fTemp36 = (fConst20 * fRec38[1]);
			fRec43[0] = (((fTemp34 + fRec43[1]) + fTemp35) + fTemp36);
			fRec41[0] = fRec43[0];
			double fRec42 = ((fTemp34 + fTemp35) + fTemp36);
			fRec40[0] = (fRec41[0] + fRec40[1]);
			fRec38[0] = fRec40[0];
			double fRec39 = fRec42;
			double fTemp37 = (fConst21 * fRec35[1]);
			double fTemp38 = (fConst22 * fRec32[1]);
			fRec37[0] = (((fRec39 + fRec37[1]) + fTemp37) + fTemp38);
			fRec35[0] = fRec37[0];
			double fRec36 = ((fRec39 + fTemp37) + fTemp38);
			fRec34[0] = (fRec35[0] + fRec34[1]);
			fRec32[0] = fRec34[0];
			double fRec33 = fRec36;
			fRec58[0] = (double(input5[i]) - (((fRec58[2] * fTemp4) + (2.0 * (fRec58[1] * fTemp6))) / fTemp7));
			double fTemp39 = ((1.2844994489999999 * (fRec18[0] * (0.0 - (((fRec58[0] + fRec58[2]) / fTemp7) + (fRec58[1] * fTemp9))))) + (((fRec58[2] + (fRec58[0] + (2.0 * fRec58[1]))) * fTemp5) / fTemp8));
			fRec59[0] = (double(input8[i]) - (((fRec59[2] * fTemp4) + (2.0 * (fRec59[1] * fTemp6))) / fTemp7));
			double fTemp40 = ((((fRec59[2] + (fRec59[0] + (2.0 * fRec59[1]))) * fTemp5) / fTemp8) + (1.2844994489999999 * (fRec18[0] * (0.0 - ((fRec59[1] * fTemp9) + ((fRec59[0] + fRec59[2]) / fTemp7))))));
			fRec60[0] = (double(input6[i]) - (((fRec60[2] * fTemp4) + (2.0 * (fRec60[1] * fTemp6))) / fTemp7));
			double fTemp41 = ((((fRec60[2] + (fRec60[0] + (2.0 * fRec60[1]))) * fTemp5) / fTemp8) + (1.2844994489999999 * (fRec18[0] * (0.0 - ((fRec60[1] * fTemp9) + ((fRec60[0] + fRec60[2]) / fTemp7))))));
			fRec61[0] = (double(input4[i]) - (((fRec61[2] * fTemp4) + (2.0 * (fRec61[1] * fTemp6))) / fTemp7));
			double fTemp42 = ((((fRec61[2] + (fRec61[0] + (2.0 * fRec61[1]))) * fTemp5) / fTemp8) + (1.2844994489999999 * (fRec18[0] * (0.0 - ((fRec61[1] * fTemp9) + ((fRec61[0] + fRec61[2]) / fTemp7))))));
			fRec62[0] = (double(input7[i]) - (((fRec62[2] * fTemp4) + (2.0 * (fRec62[1] * fTemp6))) / fTemp7));
			double fTemp43 = ((((fRec62[2] + (fRec62[0] + (2.0 * fRec62[1]))) * fTemp5) / fTemp8) + (1.2844994489999999 * (fRec18[0] * (0.0 - ((fRec62[1] * fTemp9) + ((fRec62[0] + fRec62[2]) / fTemp7))))));
			double fTemp44 = (fConst24 * (((118561916200000.0 * fTemp39) + (43822368130000.0 * fTemp40)) - (((73289665190000.0 * fTemp41) + (678701239300.0 * fTemp42)) + (242879499700000.0 * fTemp43))));
			double fTemp45 = (fConst25 * fRec52[1]);
			double fTemp46 = (fConst26 * fRec55[1]);
			fRec57[0] = (fTemp44 + (fTemp45 + (fRec57[1] + fTemp46)));
			fRec55[0] = fRec57[0];
			double fRec56 = ((fTemp46 + fTemp45) + fTemp44);
			fRec54[0] = (fRec55[0] + fRec54[1]);
			fRec52[0] = fRec54[0];
			double fRec53 = fRec56;
			double fTemp47 = (fConst28 * fRec63[1]);
			fRec72[0] = (double(input9[i]) - (((fRec72[2] * fTemp4) + (2.0 * (fRec72[1] * fTemp6))) / fTemp7));
			double fTemp48 = ((((fRec72[2] + (fRec72[0] + (2.0 * fRec72[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec72[1] * fTemp9) + ((fRec72[0] + fRec72[2]) / fTemp7))))));
			fRec73[0] = (double(input10[i]) - (((fRec73[2] * fTemp4) + (2.0 * (fRec73[1] * fTemp6))) / fTemp7));
			double fTemp49 = ((((fRec73[2] + (fRec73[0] + (2.0 * fRec73[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec73[1] * fTemp9) + ((fRec73[0] + fRec73[2]) / fTemp7))))));
			fRec74[0] = (double(input13[i]) - (((fRec74[2] * fTemp4) + (2.0 * (fRec74[1] * fTemp6))) / fTemp7));
			double fTemp50 = ((((fRec74[2] + (fRec74[0] + (2.0 * fRec74[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec74[1] * fTemp9) + ((fRec74[0] + fRec74[2]) / fTemp7))))));
			fRec75[0] = (double(input14[i]) - (((fRec75[2] * fTemp4) + (2.0 * (fRec75[1] * fTemp6))) / fTemp7));
			double fTemp51 = ((((fRec75[2] + (fRec75[0] + (2.0 * fRec75[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec75[1] * fTemp9) + ((fRec75[0] + fRec75[2]) / fTemp7))))));
			fRec76[0] = (double(input15[i]) - (((fRec76[2] * fTemp4) + (2.0 * (fRec76[1] * fTemp6))) / fTemp7));
			double fTemp52 = ((((fRec76[2] + (fRec76[0] + (2.0 * fRec76[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec76[1] * fTemp9) + ((fRec76[0] + fRec76[2]) / fTemp7))))));
			fRec77[0] = (double(input11[i]) - (((fRec77[2] * fTemp4) + (2.0 * (fRec77[1] * fTemp6))) / fTemp7));
			double fTemp53 = ((((fRec77[2] + (fRec77[0] + (2.0 * fRec77[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec77[1] * fTemp9) + ((fRec77[0] + fRec77[2]) / fTemp7))))));
			fRec78[0] = (double(input12[i]) - (((fRec78[2] * fTemp4) + (2.0 * (fRec78[1] * fTemp6))) / fTemp7));
			double fTemp54 = ((((fRec78[2] + (fRec78[0] + (2.0 * fRec78[1]))) * fTemp5) / fTemp8) + (1.0034039079999999 * (fRec18[0] * (0.0 - ((fRec78[1] * fTemp9) + ((fRec78[0] + fRec78[2]) / fTemp7))))));
			double fTemp55 = (fConst30 * ((((((72036080110000.0 * fTemp48) + (57939605740000.0 * fTemp49)) + (172061168700000.0 * fTemp50)) + (19444293700000.0 * fTemp51)) + (77613075140000.0 * fTemp52)) - ((93463136540000.0 * fTemp53) + (3238202337000.0 * fTemp54))));
			double fTemp56 = (fConst31 * fRec66[1]);
			double fTemp57 = (fConst32 * fRec69[1]);
			fRec71[0] = (fTemp55 + (fTemp56 + (fRec71[1] + fTemp57)));
			fRec69[0] = fRec71[0];
			double fRec70 = ((fTemp57 + fTemp56) + fTemp55);
			fRec68[0] = (fRec69[0] + fRec68[1]);
			fRec66[0] = fRec68[0];
			double fRec67 = fRec70;
			fRec65[0] = (fTemp47 + (fRec67 + fRec65[1]));
			fRec63[0] = fRec65[0];
			double fRec64 = (fRec67 + fTemp47);
			fRec79[0] = (double(input0[i]) - (((fRec79[2] * fTemp4) + (2.0 * (fRec79[1] * fTemp6))) / fTemp7));
			double fTemp58 = (((fTemp5 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp8) + (1.5971413109999999 * (fRec18[0] * (0.0 - ((fRec79[1] * fTemp9) + ((fRec79[0] + fRec79[2]) / fTemp7))))));
			fVec0[(IOTA & 1023)] = ((fRec2 + (fRec27 + (fRec33 + (fRec53 + fRec64)))) - (6657924290000.0 * fTemp58));
			output0[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec0[((IOTA - iConst33) & 1023)])));
			double fTemp59 = (fConst22 * fRec80[1]);
			double fTemp60 = (fConst21 * fRec83[1]);
			double fTemp61 = (fConst18 * (((22354168910000.0 * fTemp27) + ((139416279000000.0 * fTemp31) + ((87185644680000.0 * fTemp28) + (35426475310000.0 * fTemp30)))) - ((121435629300000.0 * fTemp33) + ((13348748070000.0 * fTemp32) + ((29661200090000.0 * fTemp26) + (10056786320000.0 * fTemp29))))));
			double fTemp62 = (fConst20 * fRec86[1]);
			double fTemp63 = (fConst19 * fRec89[1]);
			fRec91[0] = (fTemp61 + (fTemp62 + (fRec91[1] + fTemp63)));
			fRec89[0] = fRec91[0];
			double fRec90 = ((fTemp63 + fTemp62) + fTemp61);
			fRec88[0] = (fRec89[0] + fRec88[1]);
			fRec86[0] = fRec88[0];
			double fRec87 = fRec90;
			fRec85[0] = (fTemp59 + (fTemp60 + (fRec87 + fRec85[1])));
			fRec83[0] = fRec85[0];
			double fRec84 = (fTemp59 + (fRec87 + fTemp60));
			fRec82[0] = (fRec83[0] + fRec82[1]);
			fRec80[0] = fRec82[0];
			double fRec81 = fRec84;
			double fTemp64 = (fConst28 * fRec92[1]);
			double fTemp65 = (fConst30 * ((((((30594791520000.0 * fTemp48) + (160518661100000.0 * fTemp49)) + (94891961640000.0 * fTemp53)) + (8000293187000.0 * fTemp54)) + (15935268690000.0 * fTemp52)) - ((278999283800000.0 * fTemp50) + (38508815430000.0 * fTemp51))));
			double fTemp66 = (fConst31 * fRec95[1]);
			double fTemp67 = (fConst32 * fRec98[1]);
			fRec100[0] = (fTemp65 + (fTemp66 + (fRec100[1] + fTemp67)));
			fRec98[0] = fRec100[0];
			double fRec99 = ((fTemp67 + fTemp66) + fTemp65);
			fRec97[0] = (fRec98[0] + fRec97[1]);
			fRec95[0] = fRec97[0];
			double fRec96 = fRec99;
			fRec94[0] = (fTemp64 + (fRec96 + fRec94[1]));
			fRec92[0] = fRec94[0];
			double fRec93 = (fRec96 + fTemp64);
			double fTemp68 = (fConst24 * ((((19464453160000.0 * fTemp41) + (291618461900000.0 * fTemp43)) + (34333351520000.0 * fTemp40)) - ((89578588890000.0 * fTemp42) + (136704216300000.0 * fTemp39))));
			double fTemp69 = (fConst25 * fRec101[1]);
			double fTemp70 = (fConst26 * fRec104[1]);
			fRec106[0] = (fTemp68 + (fTemp69 + (fRec106[1] + fTemp70)));
			fRec104[0] = fRec106[0];
			double fRec105 = ((fTemp70 + fTemp69) + fTemp68);
			fRec103[0] = (fRec104[0] + fRec103[1]);
			fRec101[0] = fRec103[0];
			double fRec102 = fRec105;
			double fTemp71 = (fConst3 * fRec107[1]);
			double fTemp72 = (fConst6 * fRec110[1]);
			double fTemp73 = (fConst7 * fRec113[1]);
			double fTemp74 = (fConst9 * (((28323385770000.0 * fTemp10) + ((((31704196470000.0 * fTemp12) + (10134314110000.0 * fTemp16)) + (403269072500.0 * fTemp15)) + (49878768780000.0 * fTemp17))) - ((67783339200000.0 * fTemp14) + ((88079455710000.0 * fTemp13) + (168197930000000.0 * fTemp11)))));
			double fTemp75 = (fConst11 * fRec116[1]);
			double fTemp76 = (fConst12 * fRec119[1]);
			fRec121[0] = (fTemp74 + (fTemp75 + (fRec121[1] + fTemp76)));
			fRec119[0] = fRec121[0];
			double fRec120 = ((fTemp76 + fTemp75) + fTemp74);
			fRec118[0] = (fRec119[0] + fRec118[1]);
			fRec116[0] = fRec118[0];
			double fRec117 = fRec120;
			fRec115[0] = (fTemp72 + (fTemp73 + (fRec117 + fRec115[1])));
			fRec113[0] = fRec115[0];
			double fRec114 = (fTemp72 + (fRec117 + fTemp73));
			fRec112[0] = (fRec113[0] + fRec112[1]);
			fRec110[0] = fRec112[0];
			double fRec111 = fRec114;
			fRec109[0] = (fTemp71 + (fRec111 + fRec109[1]));
			fRec107[0] = fRec109[0];
			double fRec108 = (fRec111 + fTemp71);
			double fTemp77 = (fConst14 * ((87878000690000.0 * fTemp23) - ((85729626570000.0 * fTemp21) + (137648907000000.0 * fTemp22))));
			double fTemp78 = (fConst15 * fRec122[1]);
			fRec124[0] = (fTemp77 + (fRec124[1] + fTemp78));
			fRec122[0] = fRec124[0];
			double fRec123 = (fTemp78 + fTemp77);
			fVec1[(IOTA & 1023)] = ((64847696890000.0 * fTemp58) + (fRec81 + (fRec93 + (fRec102 + (fRec108 + fRec123)))));
			output1[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec1[((IOTA - iConst33) & 1023)])));
			double fTemp79 = (fConst3 * fRec125[1]);
			double fTemp80 = (fConst6 * fRec128[1]);
			double fTemp81 = (fConst7 * fRec131[1]);
			double fTemp82 = (fConst9 * (((46526369140000.0 * fTemp11) + (28235614980000.0 * fTemp17)) - ((94602661140000.0 * fTemp10) + (((((44956315070000.0 * fTemp12) + (7394409732000.0 * fTemp16)) + (113794885600000.0 * fTemp15)) + (48001278150000.0 * fTemp13)) + (65254312610000.0 * fTemp14)))));
			double fTemp83 = (fConst11 * fRec134[1]);
			double fTemp84 = (fConst12 * fRec137[1]);
			fRec139[0] = (fTemp82 + (fTemp83 + (fRec139[1] + fTemp84)));
			fRec137[0] = fRec139[0];
			double fRec138 = ((fTemp84 + fTemp83) + fTemp82);
			fRec136[0] = (fRec137[0] + fRec136[1]);
			fRec134[0] = fRec136[0];
			double fRec135 = fRec138;
			fRec133[0] = (fTemp80 + (fTemp81 + (fRec135 + fRec133[1])));
			fRec131[0] = fRec133[0];
			double fRec132 = (fTemp80 + (fRec135 + fTemp81));
			fRec130[0] = (fRec131[0] + fRec130[1]);
			fRec128[0] = fRec130[0];
			double fRec129 = fRec132;
			fRec127[0] = (fTemp79 + (fRec129 + fRec127[1]));
			fRec125[0] = fRec127[0];
			double fRec126 = (fRec129 + fTemp79);
			double fTemp85 = (fConst22 * fRec140[1]);
			double fTemp86 = (fConst21 * fRec143[1]);
			double fTemp87 = (fConst18 * (((305774080800000.0 * fTemp33) + ((172360704300000.0 * fTemp32) + ((18413773870000.0 * fTemp31) + ((24398055870000.0 * fTemp26) + (82367895320000.0 * fTemp30))))) - ((36333699910000.0 * fTemp27) + ((113610901700000.0 * fTemp28) + (48776830090000.0 * fTemp29)))));
			double fTemp88 = (fConst20 * fRec146[1]);
			double fTemp89 = (fConst19 * fRec149[1]);
			fRec151[0] = (fTemp87 + (fTemp88 + (fRec151[1] + fTemp89)));
			fRec149[0] = fRec151[0];
			double fRec150 = ((fTemp89 + fTemp88) + fTemp87);
			fRec148[0] = (fRec149[0] + fRec148[1]);
			fRec146[0] = fRec148[0];
			double fRec147 = fRec150;
			fRec145[0] = (fTemp85 + (fTemp86 + (fRec147 + fRec145[1])));
			fRec143[0] = fRec145[0];
			double fRec144 = (fTemp85 + (fRec147 + fTemp86));
			fRec142[0] = (fRec143[0] + fRec142[1]);
			fRec140[0] = fRec142[0];
			double fRec141 = fRec144;
			double fTemp90 = (fConst28 * fRec152[1]);
			double fTemp91 = (fConst30 * (((259303667600000.0 * fTemp50) + (21894924900000.0 * fTemp51)) - (((((166599671700000.0 * fTemp48) + (373577775200000.0 * fTemp49)) + (33497299640000.0 * fTemp53)) + (897544952500.0 * fTemp54)) + (17912591220000.0 * fTemp52))));
			double fTemp92 = (fConst31 * fRec155[1]);
			double fTemp93 = (fConst32 * fRec158[1]);
			fRec160[0] = (fTemp91 + (fTemp92 + (fRec160[1] + fTemp93)));
			fRec158[0] = fRec160[0];
			double fRec159 = ((fTemp93 + fTemp92) + fTemp91);
			fRec157[0] = (fRec158[0] + fRec157[1]);
			fRec155[0] = fRec157[0];
			double fRec156 = fRec159;
			fRec154[0] = (fTemp90 + (fRec156 + fRec154[1]));
			fRec152[0] = fRec154[0];
			double fRec153 = (fRec156 + fTemp90);
			double fTemp94 = (fConst14 * (((6213926452000.0 * fTemp21) + (252129132000000.0 * fTemp22)) - (37596824130000.0 * fTemp23)));
			double fTemp95 = (fConst15 * fRec161[1]);
			fRec163[0] = (fTemp94 + (fRec163[1] + fTemp95));
			fRec161[0] = fRec163[0];
			double fRec162 = (fTemp95 + fTemp94);
			double fTemp96 = (fConst24 * ((((226445305900000.0 * fTemp42) + (52030266280000.0 * fTemp39)) + (2388998303000.0 * fTemp40)) - ((24706550400000.0 * fTemp41) + (343854245300000.0 * fTemp43))));
			double fTemp97 = (fConst25 * fRec164[1]);
			double fTemp98 = (fConst26 * fRec167[1]);
			fRec169[0] = (fTemp96 + (fTemp97 + (fRec169[1] + fTemp98)));
			fRec167[0] = fRec169[0];
			double fRec168 = ((fTemp98 + fTemp97) + fTemp96);
			fRec166[0] = (fRec167[0] + fRec166[1]);
			fRec164[0] = fRec166[0];
			double fRec165 = fRec168;
			fVec2[(IOTA & 1023)] = ((26193597870000.0 * fTemp58) + (fRec126 + (fRec141 + (fRec153 + (fRec162 + fRec165)))));
			output2[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec2[((IOTA - iConst33) & 1023)])));
			double fTemp99 = (fConst24 * ((((60478137540000.0 * fTemp39) + (267724032800000.0 * fTemp43)) + (83807188600000.0 * fTemp40)) - ((226546260400000.0 * fTemp42) + (44246312790000.0 * fTemp41))));
			double fTemp100 = (fConst25 * fRec170[1]);
			double fTemp101 = (fConst26 * fRec173[1]);
			fRec175[0] = (fTemp99 + (fTemp100 + (fRec175[1] + fTemp101)));
			fRec173[0] = fRec175[0];
			double fRec174 = ((fTemp101 + fTemp100) + fTemp99);
			fRec172[0] = (fRec173[0] + fRec172[1]);
			fRec170[0] = fRec172[0];
			double fRec171 = fRec174;
			double fTemp102 = (fConst14 * ((34651888180000.0 * fTemp21) - ((65067832560000.0 * fTemp23) + (119774166300000.0 * fTemp22))));
			double fTemp103 = (fConst15 * fRec176[1]);
			fRec178[0] = (fTemp102 + (fRec178[1] + fTemp103));
			fRec176[0] = fRec178[0];
			double fRec177 = (fTemp103 + fTemp102);
			double fTemp104 = (fConst3 * fRec179[1]);
			double fTemp105 = (fConst6 * fRec182[1]);
			double fTemp106 = (fConst7 * fRec185[1]);
			double fTemp107 = (fConst9 * (((86122474090000.0 * fTemp10) + ((79861723420000.0 * fTemp14) + ((121056100500000.0 * fTemp13) + ((198207332800000.0 * fTemp15) + (104513430800000.0 * fTemp11))))) - (((24615010200000.0 * fTemp12) + (4811030948000.0 * fTemp16)) + (45598838280000.0 * fTemp17))));
			double fTemp108 = (fConst11 * fRec188[1]);
			double fTemp109 = (fConst12 * fRec191[1]);
			fRec193[0] = (fTemp107 + (fTemp108 + (fRec193[1] + fTemp109)));
			fRec191[0] = fRec193[0];
			double fRec192 = ((fTemp109 + fTemp108) + fTemp107);
			fRec190[0] = (fRec191[0] + fRec190[1]);
			fRec188[0] = fRec190[0];
			double fRec189 = fRec192;
			fRec187[0] = (fTemp105 + (fTemp106 + (fRec189 + fRec187[1])));
			fRec185[0] = fRec187[0];
			double fRec186 = (fTemp105 + (fRec189 + fTemp106));
			fRec184[0] = (fRec185[0] + fRec184[1]);
			fRec182[0] = fRec184[0];
			double fRec183 = fRec186;
			fRec181[0] = (fTemp104 + (fRec183 + fRec181[1]));
			fRec179[0] = fRec181[0];
			double fRec180 = (fRec183 + fTemp104);
			double fTemp110 = (fConst28 * fRec194[1]);
			double fTemp111 = (fConst30 * (((78509861600000.0 * fTemp52) + ((((130193943400000.0 * fTemp48) + (277572849200000.0 * fTemp49)) + (1712460224000.0 * fTemp54)) + (11995736210000.0 * fTemp51))) - ((29984292480000.0 * fTemp53) + (248485848200000.0 * fTemp50))));
			double fTemp112 = (fConst31 * fRec197[1]);
			double fTemp113 = (fConst32 * fRec200[1]);
			fRec202[0] = (fTemp111 + (fTemp112 + (fRec202[1] + fTemp113)));
			fRec200[0] = fRec202[0];
			double fRec201 = ((fTemp113 + fTemp112) + fTemp111);
			fRec199[0] = (fRec200[0] + fRec199[1]);
			fRec197[0] = fRec199[0];
			double fRec198 = fRec201;
			fRec196[0] = (fTemp110 + (fRec198 + fRec196[1]));
			fRec194[0] = fRec196[0];
			double fRec195 = (fRec198 + fTemp110);
			double fTemp114 = (fConst22 * fRec203[1]);
			double fTemp115 = (fConst21 * fRec206[1]);
			double fTemp116 = (fConst18 * ((87407280810000.0 * fTemp28) - ((43690811230000.0 * fTemp27) + ((201920450100000.0 * fTemp33) + ((218006324200000.0 * fTemp32) + ((79395745300000.0 * fTemp31) + ((93757826830000.0 * fTemp30) + ((3130145071000.0 * fTemp26) + (875113411000.0 * fTemp29)))))))));
			double fTemp117 = (fConst20 * fRec209[1]);
			double fTemp118 = (fConst19 * fRec212[1]);
			fRec214[0] = (fTemp116 + (fTemp117 + (fRec214[1] + fTemp118)));
			fRec212[0] = fRec214[0];
			double fRec213 = ((fTemp118 + fTemp117) + fTemp116);
			fRec211[0] = (fRec212[0] + fRec211[1]);
			fRec209[0] = fRec211[0];
			double fRec210 = fRec213;
			fRec208[0] = (fTemp114 + (fTemp115 + (fRec210 + fRec208[1])));
			fRec206[0] = fRec208[0];
			double fRec207 = (fTemp114 + (fRec210 + fTemp115));
			fRec205[0] = (fRec206[0] + fRec205[1]);
			fRec203[0] = fRec205[0];
			double fRec204 = fRec207;
			fVec3[(IOTA & 1023)] = ((14630686330000.0 * fTemp58) + (fRec171 + (fRec177 + (fRec180 + (fRec195 + fRec204)))));
			output3[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec3[((IOTA - iConst33) & 1023)])));
			double fTemp119 = (fConst3 * fRec215[1]);
			double fTemp120 = (fConst6 * fRec218[1]);
			double fTemp121 = (fConst7 * fRec221[1]);
			double fTemp122 = (fConst9 * ((((58666310020000.0 * fTemp12) + (17181315650000.0 * fTemp16)) + (6621115105000.0 * fTemp17)) - ((18563818450000.0 * fTemp10) + ((45745475900000.0 * fTemp14) + ((183888793200000.0 * fTemp13) + ((83617678450000.0 * fTemp15) + (161070892600000.0 * fTemp11)))))));
			double fTemp123 = (fConst11 * fRec224[1]);
			double fTemp124 = (fConst12 * fRec227[1]);
			fRec229[0] = (fTemp122 + (fTemp123 + (fRec229[1] + fTemp124)));
			fRec227[0] = fRec229[0];
			double fRec228 = ((fTemp124 + fTemp123) + fTemp122);
			fRec226[0] = (fRec227[0] + fRec226[1]);
			fRec224[0] = fRec226[0];
			double fRec225 = fRec228;
			fRec223[0] = (fTemp120 + (fTemp121 + (fRec225 + fRec223[1])));
			fRec221[0] = fRec223[0];
			double fRec222 = (fTemp120 + (fRec225 + fTemp121));
			fRec220[0] = (fRec221[0] + fRec220[1]);
			fRec218[0] = fRec220[0];
			double fRec219 = fRec222;
			fRec217[0] = (fTemp119 + (fRec219 + fRec217[1]));
			fRec215[0] = fRec217[0];
			double fRec216 = (fRec219 + fTemp119);
			double fTemp125 = (fConst22 * fRec230[1]);
			double fTemp126 = (fConst21 * fRec233[1]);
			double fTemp127 = (fConst18 * (((32225797200000.0 * fTemp27) + ((72139699740000.0 * fTemp33) + ((124032516000000.0 * fTemp32) + ((64800699380000.0 * fTemp30) + (28528414040000.0 * fTemp31))))) - ((30681157590000.0 * fTemp29) + ((39099094700000.0 * fTemp26) + (55705491450000.0 * fTemp28)))));
			double fTemp128 = (fConst20 * fRec236[1]);
			double fTemp129 = (fConst19 * fRec239[1]);
			fRec241[0] = (fTemp127 + (fTemp128 + (fRec241[1] + fTemp129)));
			fRec239[0] = fRec241[0];
			double fRec240 = ((fTemp129 + fTemp128) + fTemp127);
			fRec238[0] = (fRec239[0] + fRec238[1]);
			fRec236[0] = fRec238[0];
			double fRec237 = fRec240;
			fRec235[0] = (fTemp125 + (fTemp126 + (fRec237 + fRec235[1])));
			fRec233[0] = fRec235[0];
			double fRec234 = (fTemp125 + (fRec237 + fTemp126));
			fRec232[0] = (fRec233[0] + fRec232[1]);
			fRec230[0] = fRec232[0];
			double fRec231 = fRec234;
			double fTemp130 = (fConst28 * fRec242[1]);
			double fTemp131 = (fConst30 * (((103442308600.0 * fTemp51) + (((158475564000000.0 * fTemp53) + (16713707370000.0 * fTemp54)) + (135096476900000.0 * fTemp50))) - (((114000141900000.0 * fTemp48) + (23903920140000.0 * fTemp49)) + (118515368700000.0 * fTemp52))));
			double fTemp132 = (fConst31 * fRec245[1]);
			double fTemp133 = (fConst32 * fRec248[1]);
			fRec250[0] = (fTemp131 + (fTemp132 + (fRec250[1] + fTemp133)));
			fRec248[0] = fRec250[0];
			double fRec249 = ((fTemp133 + fTemp132) + fTemp131);
			fRec247[0] = (fRec248[0] + fRec247[1]);
			fRec245[0] = fRec247[0];
			double fRec246 = fRec249;
			fRec244[0] = (fTemp130 + (fRec246 + fRec244[1]));
			fRec242[0] = fRec244[0];
			double fRec243 = (fRec246 + fTemp130);
			double fTemp134 = (fConst14 * (((57944044410000.0 * fTemp23) + (146325323000000.0 * fTemp22)) - (76878551560000.0 * fTemp21)));
			double fTemp135 = (fConst15 * fRec251[1]);
			fRec253[0] = (fTemp134 + (fRec253[1] + fTemp135));
			fRec251[0] = fRec253[0];
			double fRec252 = (fTemp135 + fTemp134);
			double fTemp136 = (fConst24 * ((5348565913000.0 * fTemp41) - ((((26090616550000.0 * fTemp42) + (156185772600000.0 * fTemp39)) + (205782220700000.0 * fTemp43)) + (124729246000000.0 * fTemp40))));
			double fTemp137 = (fConst25 * fRec254[1]);
			double fTemp138 = (fConst26 * fRec257[1]);
			fRec259[0] = (fTemp136 + (fTemp137 + (fRec259[1] + fTemp138)));
			fRec257[0] = fRec259[0];
			double fRec258 = ((fTemp138 + fTemp137) + fTemp136);
			fRec256[0] = (fRec257[0] + fRec256[1]);
			fRec254[0] = fRec256[0];
			double fRec255 = fRec258;
			fVec4[(IOTA & 1023)] = ((61233985030000.0 * fTemp58) + (fRec216 + (fRec231 + (fRec243 + (fRec252 + fRec255)))));
			output4[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec4[((IOTA - iConst33) & 1023)])));
			double fTemp139 = (fConst3 * fRec260[1]);
			double fTemp140 = (fConst6 * fRec263[1]);
			double fTemp141 = (fConst7 * fRec266[1]);
			double fTemp142 = (fConst9 * (((45639090740000.0 * fTemp17) + ((104958694700000.0 * fTemp14) + ((220722549500000.0 * fTemp13) + (134521963500000.0 * fTemp11)))) - ((((32662962760000.0 * fTemp12) + (20807230910000.0 * fTemp16)) + (25261222870000.0 * fTemp15)) + (17093337210000.0 * fTemp10))));
			double fTemp143 = (fConst11 * fRec269[1]);
			double fTemp144 = (fConst12 * fRec272[1]);
			fRec274[0] = (fTemp142 + (fTemp143 + (fRec274[1] + fTemp144)));
			fRec272[0] = fRec274[0];
			double fRec273 = ((fTemp144 + fTemp143) + fTemp142);
			fRec271[0] = (fRec272[0] + fRec271[1]);
			fRec269[0] = fRec271[0];
			double fRec270 = fRec273;
			fRec268[0] = (fTemp140 + (fTemp141 + (fRec270 + fRec268[1])));
			fRec266[0] = fRec268[0];
			double fRec267 = (fTemp140 + (fRec270 + fTemp141));
			fRec265[0] = (fRec266[0] + fRec265[1]);
			fRec263[0] = fRec265[0];
			double fRec264 = fRec267;
			fRec262[0] = (fTemp139 + (fRec264 + fRec262[1]));
			fRec260[0] = fRec262[0];
			double fRec261 = (fRec264 + fTemp139);
			double fTemp145 = (fConst22 * fRec275[1]);
			double fTemp146 = (fConst21 * fRec278[1]);
			double fTemp147 = (fConst18 * (((47824303670000.0 * fTemp27) + ((90851890830000.0 * fTemp33) + ((126800741500000.0 * fTemp29) + ((57611837780000.0 * fTemp26) + (72820900060000.0 * fTemp28))))) - ((14616295410000.0 * fTemp32) + ((66668070110000.0 * fTemp30) + (19967738670000.0 * fTemp31)))));
			double fTemp148 = (fConst20 * fRec281[1]);
			double fTemp149 = (fConst19 * fRec284[1]);
			fRec286[0] = (fTemp147 + (fTemp148 + (fRec286[1] + fTemp149)));
			fRec284[0] = fRec286[0];
			double fRec285 = ((fTemp149 + fTemp148) + fTemp147);
			fRec283[0] = (fRec284[0] + fRec283[1]);
			fRec281[0] = fRec283[0];
			double fRec282 = fRec285;
			fRec280[0] = (fTemp145 + (fTemp146 + (fRec282 + fRec280[1])));
			fRec278[0] = fRec280[0];
			double fRec279 = (fTemp145 + (fRec282 + fTemp146));
			fRec277[0] = (fRec278[0] + fRec277[1]);
			fRec275[0] = fRec277[0];
			double fRec276 = fRec279;
			double fTemp150 = (fConst30 * (((46123527240000.0 * fTemp52) + (49339276800000.0 * fTemp48)) - (((((116657057300000.0 * fTemp49) + (130961485500000.0 * fTemp53)) + (3464969599000.0 * fTemp54)) + (192241369200000.0 * fTemp50)) + (50646659340000.0 * fTemp51))));
			double fTemp151 = (fConst32 * fRec293[1]);
			double fTemp152 = (fConst31 * fRec290[1]);
			fRec295[0] = (((fTemp150 + fRec295[1]) + fTemp151) + fTemp152);
			fRec293[0] = fRec295[0];
			double fRec294 = ((fTemp150 + fTemp151) + fTemp152);
			fRec292[0] = (fRec293[0] + fRec292[1]);
			fRec290[0] = fRec292[0];
			double fRec291 = fRec294;
			double fTemp153 = (fConst28 * fRec287[1]);
			fRec289[0] = ((fRec291 + fRec289[1]) + fTemp153);
			fRec287[0] = fRec289[0];
			double fRec288 = (fRec291 + fTemp153);
			double fTemp154 = (fConst14 * ((45637758130000.0 * fTemp21) - ((170141326400000.0 * fTemp23) + (129740275400000.0 * fTemp22))));
			double fTemp155 = (fConst15 * fRec296[1]);
			fRec298[0] = (fTemp154 + (fRec298[1] + fTemp155));
			fRec296[0] = fRec298[0];
			double fRec297 = (fTemp155 + fTemp154);
			double fTemp156 = (fConst24 * (((((54141587540000.0 * fTemp42) + (209213791100000.0 * fTemp39)) + (240928392000000.0 * fTemp43)) + (120094843200000.0 * fTemp40)) - (46458817730000.0 * fTemp41)));
			double fTemp157 = (fConst25 * fRec299[1]);
			double fTemp158 = (fConst26 * fRec302[1]);
			fRec304[0] = (fTemp156 + (fTemp157 + (fRec304[1] + fTemp158)));
			fRec302[0] = fRec304[0];
			double fRec303 = ((fTemp158 + fTemp157) + fTemp156);
			fRec301[0] = (fRec302[0] + fRec301[1]);
			fRec299[0] = fRec301[0];
			double fRec300 = fRec303;
			fVec5[(IOTA & 1023)] = ((11078960500000.0 * fTemp58) + (fRec261 + (fRec276 + (fRec288 + (fRec297 + fRec300)))));
			output5[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec5[((IOTA - iConst33) & 1023)])));
			double fTemp159 = (fConst3 * fRec305[1]);
			double fTemp160 = (fConst6 * fRec308[1]);
			double fTemp161 = (fConst7 * fRec311[1]);
			double fTemp162 = (fConst9 * (((46399094120000.0 * fTemp10) + ((98945472130000.0 * fTemp15) + ((427987823200.0 * fTemp16) + (10796407590000.0 * fTemp11)))) - ((((37466911100000.0 * fTemp12) + (108169400900000.0 * fTemp13)) + (65245321620000.0 * fTemp14)) + (44789825670000.0 * fTemp17))));
			double fTemp163 = (fConst11 * fRec314[1]);
			double fTemp164 = (fConst12 * fRec317[1]);
			fRec319[0] = (fTemp162 + (fTemp163 + (fRec319[1] + fTemp164)));
			fRec317[0] = fRec319[0];
			double fRec318 = ((fTemp164 + fTemp163) + fTemp162);
			fRec316[0] = (fRec317[0] + fRec316[1]);
			fRec314[0] = fRec316[0];
			double fRec315 = fRec318;
			fRec313[0] = (fTemp160 + (fTemp161 + (fRec315 + fRec313[1])));
			fRec311[0] = fRec313[0];
			double fRec312 = (fTemp160 + (fRec315 + fTemp161));
			fRec310[0] = (fRec311[0] + fRec310[1]);
			fRec308[0] = fRec310[0];
			double fRec309 = fRec312;
			fRec307[0] = (fTemp159 + (fRec309 + fRec307[1]));
			fRec305[0] = fRec307[0];
			double fRec306 = (fRec309 + fTemp159);
			double fTemp165 = (fConst30 * (((((((174334201800000.0 * fTemp48) + (176906443400000.0 * fTemp49)) + (182977240100000.0 * fTemp53)) + (2089972010000.0 * fTemp54)) + (189485842900000.0 * fTemp50)) + (114243796200000.0 * fTemp51)) - (20233596280000.0 * fTemp52)));
			double fTemp166 = (fConst32 * fRec326[1]);
			double fTemp167 = (fConst31 * fRec323[1]);
			fRec328[0] = (((fTemp165 + fRec328[1]) + fTemp166) + fTemp167);
			fRec326[0] = fRec328[0];
			double fRec327 = ((fTemp165 + fTemp166) + fTemp167);
			fRec325[0] = (fRec326[0] + fRec325[1]);
			fRec323[0] = fRec325[0];
			double fRec324 = fRec327;
			double fTemp168 = (fConst28 * fRec320[1]);
			fRec322[0] = ((fRec324 + fRec322[1]) + fTemp168);
			fRec320[0] = fRec322[0];
			double fRec321 = (fRec324 + fTemp168);
			double fTemp169 = (fConst14 * (((63223207320000.0 * fTemp23) + (124203671600000.0 * fTemp22)) - (11369365290000.0 * fTemp21)));
			double fTemp170 = (fConst15 * fRec329[1]);
			fRec331[0] = ((fTemp169 + fRec331[1]) + fTemp170);
			fRec329[0] = fRec331[0];
			double fRec330 = (fTemp169 + fTemp170);
			double fTemp171 = (fConst24 * (0.0 - ((((98315021720000.0 * fTemp42) + ((184926191700000.0 * fTemp39) + (18481555640000.0 * fTemp41))) + (223534795000000.0 * fTemp43)) + (202365490000000.0 * fTemp40))));
			double fTemp172 = (fConst25 * fRec332[1]);
			double fTemp173 = (fConst26 * fRec335[1]);
			fRec337[0] = (fTemp171 + (fTemp172 + (fRec337[1] + fTemp173)));
			fRec335[0] = fRec337[0];
			double fRec336 = ((fTemp173 + fTemp172) + fTemp171);
			fRec334[0] = (fRec335[0] + fRec334[1]);
			fRec332[0] = fRec334[0];
			double fRec333 = fRec336;
			double fTemp174 = (fConst18 * (((51942880290000.0 * fTemp30) + (45753646770000.0 * fTemp31)) - ((38693238120000.0 * fTemp27) + ((155268378600000.0 * fTemp33) + ((146593653400000.0 * fTemp32) + (((64388153060000.0 * fTemp26) + (72370881890000.0 * fTemp28)) + (91499788480000.0 * fTemp29)))))));
			double fTemp175 = (fConst20 * fRec344[1]);
			double fTemp176 = (fConst19 * fRec347[1]);
			fRec349[0] = (fTemp174 + (fTemp175 + (fRec349[1] + fTemp176)));
			fRec347[0] = fRec349[0];
			double fRec348 = ((fTemp176 + fTemp175) + fTemp174);
			fRec346[0] = (fRec347[0] + fRec346[1]);
			fRec344[0] = fRec346[0];
			double fRec345 = fRec348;
			double fTemp177 = (fConst22 * fRec338[1]);
			double fTemp178 = (fConst21 * fRec341[1]);
			fRec343[0] = (fRec345 + (fTemp177 + (fRec343[1] + fTemp178)));
			fRec341[0] = fRec343[0];
			double fRec342 = (fRec345 + (fTemp178 + fTemp177));
			fRec340[0] = (fRec340[1] + fRec341[0]);
			fRec338[0] = fRec340[0];
			double fRec339 = fRec342;
			fVec6[(IOTA & 1023)] = ((34730824030000.0 * fTemp58) + (fRec306 + ((fRec321 + (fRec330 + fRec333)) + fRec339)));
			output6[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec6[((IOTA - iConst33) & 1023)])));
			double fTemp179 = (fConst28 * fRec350[1]);
			double fTemp180 = (fConst30 * (((12304874920000.0 * fTemp54) + (63735312090000.0 * fTemp52)) - (((((230273384600000.0 * fTemp48) + (113475155200000.0 * fTemp49)) + (77750186960000.0 * fTemp53)) + (125290083200000.0 * fTemp50)) + (141361653600000.0 * fTemp51))));
			double fTemp181 = (fConst31 * fRec353[1]);
			double fTemp182 = (fConst32 * fRec356[1]);
			fRec358[0] = (fTemp180 + (fTemp181 + (fRec358[1] + fTemp182)));
			fRec356[0] = fRec358[0];
			double fRec357 = ((fTemp182 + fTemp181) + fTemp180);
			fRec355[0] = (fRec356[0] + fRec355[1]);
			fRec353[0] = fRec355[0];
			double fRec354 = fRec357;
			fRec352[0] = (fTemp179 + (fRec354 + fRec352[1]));
			fRec350[0] = fRec352[0];
			double fRec351 = (fRec354 + fTemp179);
			double fTemp183 = (fConst24 * (((((123301520000000.0 * fTemp42) + (140310820900000.0 * fTemp39)) + (167366194700000.0 * fTemp43)) + (103201538500000.0 * fTemp40)) - (9078213194000.0 * fTemp41)));
			double fTemp184 = (fConst25 * fRec359[1]);
			double fTemp185 = (fConst26 * fRec362[1]);
			fRec364[0] = (fTemp183 + (fTemp184 + (fRec364[1] + fTemp185)));
			fRec362[0] = fRec364[0];
			double fRec363 = ((fTemp185 + fTemp184) + fTemp183);
			fRec361[0] = (fRec362[0] + fRec361[1]);
			fRec359[0] = fRec361[0];
			double fRec360 = fRec363;
			double fTemp186 = (fConst14 * (0.0 - (((117935953700000.0 * fTemp23) + (45678384750000.0 * fTemp21)) + (131269886400000.0 * fTemp22))));
			double fTemp187 = (fConst15 * fRec365[1]);
			fRec367[0] = (fTemp186 + (fRec367[1] + fTemp187));
			fRec365[0] = fRec367[0];
			double fRec366 = (fTemp187 + fTemp186);
			double fTemp188 = (fConst22 * fRec368[1]);
			double fTemp189 = (fConst21 * fRec371[1]);
			double fTemp190 = (fConst18 * (((68621201370000.0 * fTemp33) + ((261806080400000.0 * fTemp32) + ((137041266300000.0 * fTemp29) + ((54107255910000.0 * fTemp26) + (52698639120000.0 * fTemp28))))) - ((46721025270000.0 * fTemp27) + ((27642048460000.0 * fTemp30) + (4893083956000.0 * fTemp31)))));
			double fTemp191 = (fConst20 * fRec374[1]);
			double fTemp192 = (fConst19 * fRec377[1]);
			fRec379[0] = (fTemp190 + (fTemp191 + (fRec379[1] + fTemp192)));
			fRec377[0] = fRec379[0];
			double fRec378 = ((fTemp192 + fTemp191) + fTemp190);
			fRec376[0] = (fRec377[0] + fRec376[1]);
			fRec374[0] = fRec376[0];
			double fRec375 = fRec378;
			fRec373[0] = (fTemp188 + (fTemp189 + (fRec375 + fRec373[1])));
			fRec371[0] = fRec373[0];
			double fRec372 = (fTemp188 + (fRec375 + fTemp189));
			fRec370[0] = (fRec371[0] + fRec370[1]);
			fRec368[0] = fRec370[0];
			double fRec369 = fRec372;
			double fTemp193 = (((fConst12 * fRec392[1]) + (fConst11 * fRec389[1])) + (fConst9 * ((((56775350280000.0 * fTemp12) + (17736158150000.0 * fTemp16)) + (16615411410000.0 * fTemp13)) - ((42283587400000.0 * fTemp10) + ((7730879116000.0 * fTemp17) + ((29014341740000.0 * fTemp14) + ((198168851300000.0 * fTemp15) + (89101992770000.0 * fTemp11))))))));
			fRec394[0] = (fTemp193 + fRec394[1]);
			fRec392[0] = fRec394[0];
			double fRec393 = fTemp193;
			fRec391[0] = (fRec392[0] + fRec391[1]);
			fRec389[0] = fRec391[0];
			double fRec390 = fRec393;
			double fTemp194 = (fConst7 * fRec386[1]);
			double fTemp195 = (fConst6 * fRec383[1]);
			fRec388[0] = (((fRec390 + fRec388[1]) + fTemp194) + fTemp195);
			fRec386[0] = fRec388[0];
			double fRec387 = ((fRec390 + fTemp194) + fTemp195);
			fRec385[0] = (fRec386[0] + fRec385[1]);
			fRec383[0] = fRec385[0];
			double fRec384 = fRec387;
			double fTemp196 = (fConst3 * fRec380[1]);
			fRec382[0] = ((fRec384 + fRec382[1]) + fTemp196);
			fRec380[0] = fRec382[0];
			double fRec381 = (fRec384 + fTemp196);
			fVec7[(IOTA & 1023)] = ((48925355020000.0 * fTemp58) + (fRec351 + (fRec360 + (fRec366 + (fRec369 + fRec381)))));
			output7[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec7[((IOTA - iConst33) & 1023)])));
			double fTemp197 = (fConst3 * fRec395[1]);
			double fTemp198 = (fConst9 * (((523765461700.0 * fTemp10) + ((53409452920000.0 * fTemp17) + ((21892423810000.0 * fTemp14) + ((110840029200000.0 * fTemp13) + ((284688621500000.0 * fTemp15) + (135519607200000.0 * fTemp11)))))) - ((22434512580000.0 * fTemp12) + (20225106210000.0 * fTemp16))));
			double fTemp199 = (fConst11 * fRec404[1]);
			double fTemp200 = (fConst12 * fRec407[1]);
			fRec409[0] = (fTemp198 + (fTemp199 + (fRec409[1] + fTemp200)));
			fRec407[0] = fRec409[0];
			double fRec408 = ((fTemp200 + fTemp199) + fTemp198);
			fRec406[0] = (fRec407[0] + fRec406[1]);
			fRec404[0] = fRec406[0];
			double fRec405 = fRec408;
			double fTemp201 = ((fConst6 * fRec398[1]) + (fRec405 + (fConst7 * fRec401[1])));
			fRec403[0] = (fRec403[1] + fTemp201);
			fRec401[0] = fRec403[0];
			double fRec402 = fTemp201;
			fRec400[0] = (fRec401[0] + fRec400[1]);
			fRec398[0] = fRec400[0];
			double fRec399 = fRec402;
			fRec397[0] = (fTemp197 + (fRec399 + fRec397[1]));
			fRec395[0] = fRec397[0];
			double fRec396 = (fRec399 + fTemp197);
			double fTemp202 = (fConst22 * fRec410[1]);
			double fTemp203 = (fConst21 * fRec413[1]);
			double fTemp204 = (fConst18 * (((57267124050000.0 * fTemp27) + (16906822420000.0 * fTemp30)) - ((21561539330000.0 * fTemp33) + ((346639031100000.0 * fTemp32) + ((((59608983450000.0 * fTemp26) + (36521035250000.0 * fTemp28)) + (104093681900000.0 * fTemp29)) + (102546417300000.0 * fTemp31))))));
			double fTemp205 = (fConst20 * fRec416[1]);
			double fTemp206 = (fConst19 * fRec419[1]);
			fRec421[0] = (fTemp204 + (fTemp205 + (fRec421[1] + fTemp206)));
			fRec419[0] = fRec421[0];
			double fRec420 = ((fTemp206 + fTemp205) + fTemp204);
			fRec418[0] = (fRec419[0] + fRec418[1]);
			fRec416[0] = fRec418[0];
			double fRec417 = fRec420;
			fRec415[0] = (fTemp202 + (fTemp203 + (fRec417 + fRec415[1])));
			fRec413[0] = fRec415[0];
			double fRec414 = (fTemp202 + (fRec417 + fTemp203));
			fRec412[0] = (fRec413[0] + fRec412[1]);
			fRec410[0] = fRec412[0];
			double fRec411 = fRec414;
			double fTemp207 = (fConst28 * fRec422[1]);
			double fTemp208 = (fConst30 * (((8858262871000.0 * fTemp52) + ((131568567800000.0 * fTemp51) + ((((223312940800000.0 * fTemp48) + (111552203200000.0 * fTemp53)) + (1536954413000.0 * fTemp54)) + (121011626300000.0 * fTemp50)))) - (31604674470000.0 * fTemp49)));
			double fTemp209 = (fConst31 * fRec425[1]);
			double fTemp210 = (fConst32 * fRec428[1]);
			fRec430[0] = (fTemp208 + (fTemp209 + (fRec430[1] + fTemp210)));
			fRec428[0] = fRec430[0];
			double fRec429 = ((fTemp210 + fTemp209) + fTemp208);
			fRec427[0] = (fRec428[0] + fRec427[1]);
			fRec425[0] = fRec427[0];
			double fRec426 = fRec429;
			fRec424[0] = (fTemp207 + (fRec426 + fRec424[1]));
			fRec422[0] = fRec424[0];
			double fRec423 = (fRec426 + fTemp207);
			double fTemp211 = (fConst14 * (((35757570990000.0 * fTemp23) + (52810579930000.0 * fTemp21)) + (17754085030000.0 * fTemp22)));
			double fTemp212 = (fConst15 * fRec431[1]);
			fRec433[0] = (fTemp211 + (fRec433[1] + fTemp212));
			fRec431[0] = fRec433[0];
			double fRec432 = (fTemp212 + fTemp211);
			double fTemp213 = (fConst24 * ((63341226560000.0 * fTemp42) - ((((113865219600000.0 * fTemp39) + (55691044800000.0 * fTemp41)) + (89892253190000.0 * fTemp43)) + (17761940450000.0 * fTemp40))));
			double fTemp214 = (fConst25 * fRec434[1]);
			double fTemp215 = (fConst26 * fRec437[1]);
			fRec439[0] = (fTemp213 + (fTemp214 + (fRec439[1] + fTemp215)));
			fRec437[0] = fRec439[0];
			double fRec438 = ((fTemp215 + fTemp214) + fTemp213);
			fRec436[0] = (fRec437[0] + fRec436[1]);
			fRec434[0] = fRec436[0];
			double fRec435 = fRec438;
			fVec8[(IOTA & 1023)] = ((7955281454000.0 * fTemp58) + (fRec396 + (fRec411 + (fRec423 + (fRec432 + fRec435)))));
			output8[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec8[((IOTA - iConst33) & 1023)])));
			double fTemp216 = (fConst9 * (((10117290810000.0 * fTemp16) + (38276164480000.0 * fTemp10)) - ((47313792040000.0 * fTemp17) + ((15866238010000.0 * fTemp14) + ((234397503000000.0 * fTemp13) + ((219429809300000.0 * fTemp15) + ((33300942150000.0 * fTemp12) + (165583000100000.0 * fTemp11))))))));
			double fTemp217 = (fConst12 * fRec452[1]);
			double fTemp218 = (fConst11 * fRec449[1]);
			fRec454[0] = (((fTemp216 + fRec454[1]) + fTemp217) + fTemp218);
			fRec452[0] = fRec454[0];
			double fRec453 = ((fTemp216 + fTemp217) + fTemp218);
			fRec451[0] = (fRec452[0] + fRec451[1]);
			fRec449[0] = fRec451[0];
			double fRec450 = fRec453;
			double fTemp219 = (fConst7 * fRec446[1]);
			double fTemp220 = (fConst6 * fRec443[1]);
			fRec448[0] = (((fRec450 + fRec448[1]) + fTemp219) + fTemp220);
			fRec446[0] = fRec448[0];
			double fRec447 = ((fRec450 + fTemp219) + fTemp220);
			fRec445[0] = (fRec446[0] + fRec445[1]);
			fRec443[0] = fRec445[0];
			double fRec444 = fRec447;
			double fTemp221 = (fConst3 * fRec440[1]);
			fRec442[0] = ((fRec444 + fRec442[1]) + fTemp221);
			fRec440[0] = fRec442[0];
			double fRec441 = (fRec444 + fTemp221);
			double fTemp222 = (fConst14 * (0.0 - (((88451717620000.0 * fTemp23) + (87858187730000.0 * fTemp21)) + (63263299910000.0 * fTemp22))));
			double fTemp223 = (fConst15 * fRec455[1]);
			fRec457[0] = (fTemp222 + (fRec457[1] + fTemp223));
			fRec455[0] = fRec457[0];
			double fRec456 = (fTemp223 + fTemp222);
			double fTemp224 = (fConst24 * ((((143481975300000.0 * fTemp39) + (18141679370000.0 * fTemp41)) + (23598192450000.0 * fTemp43)) - ((120457451800000.0 * fTemp42) + (24957464770000.0 * fTemp40))));
			double fTemp225 = (fConst25 * fRec458[1]);
			double fTemp226 = (fConst26 * fRec461[1]);
			fRec463[0] = (fTemp224 + (fTemp225 + (fRec463[1] + fTemp226)));
			fRec461[0] = fRec463[0];
			double fRec462 = ((fTemp226 + fTemp225) + fTemp224);
			fRec460[0] = (fRec460[1] + fRec461[0]);
			fRec458[0] = fRec460[0];
			double fRec459 = fRec462;
			double fTemp227 = (fConst28 * fRec464[1]);
			double fTemp228 = (fConst30 * ((((207314328200000.0 * fTemp49) + (10793666310000.0 * fTemp54)) + (5522156364000.0 * fTemp50)) - ((74731024620000.0 * fTemp52) + (((281267037800000.0 * fTemp48) + (120847558800000.0 * fTemp53)) + (70612801360000.0 * fTemp51)))));
			double fTemp229 = (fConst31 * fRec467[1]);
			double fTemp230 = (fConst32 * fRec470[1]);
			fRec472[0] = (fTemp228 + (fTemp229 + (fRec472[1] + fTemp230)));
			fRec470[0] = fRec472[0];
			double fRec471 = ((fTemp230 + fTemp229) + fTemp228);
			fRec469[0] = (fRec469[1] + fRec470[0]);
			fRec467[0] = fRec469[0];
			double fRec468 = fRec471;
			fRec466[0] = ((fRec466[1] + fTemp227) + fRec468);
			fRec464[0] = fRec466[0];
			double fRec465 = (fTemp227 + fRec468);
			double fTemp231 = (fConst22 * fRec473[1]);
			double fTemp232 = (fConst21 * fRec476[1]);
			double fTemp233 = (fConst18 * (((23236356340000.0 * fTemp27) + ((342127043800000.0 * fTemp32) + ((136108574400000.0 * fTemp31) + (((68558954220000.0 * fTemp26) + (8966782469000.0 * fTemp28)) + (8141197329000.0 * fTemp30))))) - ((154163915700000.0 * fTemp33) + (21535016070000.0 * fTemp29))));
			double fTemp234 = (fConst20 * fRec479[1]);
			double fTemp235 = (fConst19 * fRec482[1]);
			fRec484[0] = (fTemp233 + (fTemp234 + (fRec484[1] + fTemp235)));
			fRec482[0] = fRec484[0];
			double fRec483 = ((fTemp235 + fTemp234) + fTemp233);
			fRec481[0] = (fRec482[0] + fRec481[1]);
			fRec479[0] = fRec481[0];
			double fRec480 = fRec483;
			fRec478[0] = (fTemp231 + (fTemp232 + (fRec478[1] + fRec480)));
			fRec476[0] = fRec478[0];
			double fRec477 = (fTemp231 + (fRec480 + fTemp232));
			fRec475[0] = (fRec475[1] + fRec476[0]);
			fRec473[0] = fRec475[0];
			double fRec474 = fRec477;
			fVec9[(IOTA & 1023)] = ((fRec441 + (((fRec456 + fRec459) + fRec465) + fRec474)) + (65854877120000.0 * fTemp58));
			output9[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec9[((IOTA - iConst33) & 1023)])));
			double fTemp236 = (fConst3 * fRec485[1]);
			double fTemp237 = (fConst6 * fRec488[1]);
			double fTemp238 = (fConst7 * fRec491[1]);
			double fTemp239 = (fConst9 * (((105922490400000.0 * fTemp14) + ((229646664400000.0 * fTemp13) + ((84203199690000.0 * fTemp15) + ((48608012380000.0 * fTemp12) + (172835531700000.0 * fTemp11))))) - ((65729990410000.0 * fTemp10) + ((7403730898000.0 * fTemp16) + (25967008640000.0 * fTemp17)))));
			double fTemp240 = (fConst11 * fRec494[1]);
			double fTemp241 = (fConst12 * fRec497[1]);
			fRec499[0] = (fTemp239 + (fTemp240 + (fRec499[1] + fTemp241)));
			fRec497[0] = fRec499[0];
			double fRec498 = ((fTemp241 + fTemp240) + fTemp239);
			fRec496[0] = (fRec497[0] + fRec496[1]);
			fRec494[0] = fRec496[0];
			double fRec495 = fRec498;
			fRec493[0] = (fTemp237 + (fTemp238 + (fRec495 + fRec493[1])));
			fRec491[0] = fRec493[0];
			double fRec492 = (fTemp237 + (fRec495 + fTemp238));
			fRec490[0] = (fRec491[0] + fRec490[1]);
			fRec488[0] = fRec490[0];
			double fRec489 = fRec492;
			fRec487[0] = (fTemp236 + (fRec489 + fRec487[1]));
			fRec485[0] = fRec487[0];
			double fRec486 = (fRec489 + fTemp236);
			double fTemp242 = (fConst22 * fRec500[1]);
			double fTemp243 = (fConst21 * fRec503[1]);
			double fTemp244 = (fConst18 * (((244905487300000.0 * fTemp33) + ((20573798580000.0 * fTemp28) + (73493783820000.0 * fTemp29))) - ((39912002880000.0 * fTemp27) + ((173682441100000.0 * fTemp32) + ((44703523680000.0 * fTemp31) + ((78609094840000.0 * fTemp26) + (81824280340000.0 * fTemp30)))))));
			double fTemp245 = (fConst20 * fRec506[1]);
			double fTemp246 = (fConst19 * fRec509[1]);
			fRec511[0] = (fTemp244 + (fTemp245 + (fRec511[1] + fTemp246)));
			fRec509[0] = fRec511[0];
			double fRec510 = ((fTemp246 + fTemp245) + fTemp244);
			fRec508[0] = (fRec509[0] + fRec508[1]);
			fRec506[0] = fRec508[0];
			double fRec507 = fRec510;
			fRec505[0] = (fTemp242 + (fTemp243 + (fRec507 + fRec505[1])));
			fRec503[0] = fRec505[0];
			double fRec504 = (fTemp242 + (fRec507 + fTemp243));
			fRec502[0] = (fRec503[0] + fRec502[1]);
			fRec500[0] = fRec502[0];
			double fRec501 = fRec504;
			double fTemp247 = (fConst28 * fRec512[1]);
			double fTemp248 = (fConst30 * ((((156452830300000.0 * fTemp48) + (165312626200000.0 * fTemp53)) + (36752288310000.0 * fTemp52)) - ((((315830496700000.0 * fTemp49) + (6303842130000.0 * fTemp54)) + (4696365720000.0 * fTemp50)) + (68501324430000.0 * fTemp51))));
			double fTemp249 = (fConst31 * fRec515[1]);
			double fTemp250 = (fConst32 * fRec518[1]);
			fRec520[0] = (fTemp248 + (fTemp249 + (fRec520[1] + fTemp250)));
			fRec518[0] = fRec520[0];
			double fRec519 = ((fTemp250 + fTemp249) + fTemp248);
			fRec517[0] = (fRec518[0] + fRec517[1]);
			fRec515[0] = fRec517[0];
			double fRec516 = fRec519;
			fRec514[0] = (fTemp247 + (fRec516 + fRec514[1]));
			fRec512[0] = fRec514[0];
			double fRec513 = (fRec516 + fTemp247);
			double fTemp251 = (fConst14 * (((128272211900000.0 * fTemp23) + (62515531600000.0 * fTemp21)) - (70152063440000.0 * fTemp22)));
			double fTemp252 = (fConst15 * fRec521[1]);
			fRec523[0] = (fTemp251 + (fRec523[1] + fTemp252));
			fRec521[0] = fRec523[0];
			double fRec522 = (fTemp252 + fTemp251);
			double fTemp253 = (fConst24 * ((((181830645600000.0 * fTemp42) + (52914894010000.0 * fTemp43)) + (224452317700000.0 * fTemp40)) - ((190186235900000.0 * fTemp39) + (53762279130000.0 * fTemp41))));
			double fTemp254 = (fConst25 * fRec524[1]);
			double fTemp255 = (fConst26 * fRec527[1]);
			fRec529[0] = (fTemp253 + (fTemp254 + (fRec529[1] + fTemp255)));
			fRec527[0] = fRec529[0];
			double fRec528 = ((fTemp255 + fTemp254) + fTemp253);
			fRec526[0] = (fRec527[0] + fRec526[1]);
			fRec524[0] = fRec526[0];
			double fRec525 = fRec528;
			fVec10[(IOTA & 1023)] = ((4132174371000.0 * fTemp58) + (fRec486 + (fRec501 + (fRec513 + (fRec522 + fRec525)))));
			output10[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec10[((IOTA - iConst33) & 1023)])));
			double fTemp256 = (fConst3 * fRec530[1]);
			double fTemp257 = (fConst6 * fRec533[1]);
			double fTemp258 = (fConst7 * fRec536[1]);
			double fTemp259 = (fConst9 * (((54390841240000.0 * fTemp10) + (((5872447703000.0 * fTemp12) + (10832018030000.0 * fTemp16)) + (57160433720000.0 * fTemp17))) - ((107550946900000.0 * fTemp14) + ((167944778200000.0 * fTemp13) + ((1768933017000.0 * fTemp15) + (102034187800000.0 * fTemp11))))));
			double fTemp260 = (fConst11 * fRec539[1]);
			double fTemp261 = (fConst12 * fRec542[1]);
			fRec544[0] = (fTemp259 + (fTemp260 + (fRec544[1] + fTemp261)));
			fRec542[0] = fRec544[0];
			double fRec543 = ((fTemp261 + fTemp260) + fTemp259);
			fRec541[0] = (fRec542[0] + fRec541[1]);
			fRec539[0] = fRec541[0];
			double fRec540 = fRec543;
			fRec538[0] = (fTemp257 + (fTemp258 + (fRec540 + fRec538[1])));
			fRec536[0] = fRec538[0];
			double fRec537 = (fTemp257 + (fRec540 + fTemp258));
			fRec535[0] = (fRec536[0] + fRec535[1]);
			fRec533[0] = fRec535[0];
			double fRec534 = fRec537;
			fRec532[0] = (fTemp256 + (fRec534 + fRec532[1]));
			fRec530[0] = fRec532[0];
			double fRec531 = (fRec534 + fTemp256);
			double fTemp262 = (fConst22 * fRec545[1]);
			double fTemp263 = (fConst21 * fRec548[1]);
			double fTemp264 = (fConst18 * (((3998368783000.0 * fTemp31) + ((75554370830000.0 * fTemp26) + (122982497800000.0 * fTemp30))) - ((42572202220000.0 * fTemp27) + ((136706518400000.0 * fTemp33) + ((29548138380000.0 * fTemp32) + ((29667070070000.0 * fTemp28) + (200244275600000.0 * fTemp29)))))));
			double fTemp265 = (fConst20 * fRec551[1]);
			double fTemp266 = (fConst19 * fRec554[1]);
			fRec556[0] = (fTemp264 + (fTemp265 + (fRec556[1] + fTemp266)));
			fRec554[0] = fRec556[0];
			double fRec555 = ((fTemp266 + fTemp265) + fTemp264);
			fRec553[0] = (fRec554[0] + fRec553[1]);
			fRec551[0] = fRec553[0];
			double fRec552 = fRec555;
			fRec550[0] = (fTemp262 + (fTemp263 + (fRec552 + fRec550[1])));
			fRec548[0] = fRec550[0];
			double fRec549 = (fTemp262 + (fRec552 + fTemp263));
			fRec547[0] = (fRec548[0] + fRec547[1]);
			fRec545[0] = fRec547[0];
			double fRec546 = fRec549;
			double fTemp267 = (fConst28 * fRec557[1]);
			double fTemp268 = (fConst30 * (((183296511000000.0 * fTemp51) + ((((75227099420000.0 * fTemp48) + (228708496600000.0 * fTemp49)) + (13002950320000.0 * fTemp54)) + (80319981370000.0 * fTemp50))) - ((205550758100000.0 * fTemp53) + (89353828610000.0 * fTemp52))));
			double fTemp269 = (fConst31 * fRec560[1]);
			double fTemp270 = (fConst32 * fRec563[1]);
			fRec565[0] = (fTemp268 + (fTemp269 + (fRec565[1] + fTemp270)));
			fRec563[0] = fRec565[0];
			double fRec564 = ((fTemp270 + fTemp269) + fTemp268);
			fRec562[0] = (fRec563[0] + fRec562[1]);
			fRec560[0] = fRec562[0];
			double fRec561 = fRec564;
			fRec559[0] = (fTemp267 + (fRec561 + fRec559[1]));
			fRec557[0] = fRec559[0];
			double fRec558 = (fRec561 + fTemp267);
			double fTemp271 = (fConst14 * (0.0 - (((105997818600000.0 * fTemp23) + (52059923340000.0 * fTemp21)) + (3806211110000.0 * fTemp22))));
			double fTemp272 = (fConst15 * fRec566[1]);
			fRec568[0] = (fTemp271 + (fRec568[1] + fTemp272));
			fRec566[0] = fRec568[0];
			double fRec567 = (fTemp272 + fTemp271);
			double fTemp273 = (fConst24 * ((209053294800000.0 * fTemp39) - ((((191568402800000.0 * fTemp42) + (3921127746000.0 * fTemp41)) + (62122326030000.0 * fTemp43)) + (219652699700000.0 * fTemp40))));
			double fTemp274 = (fConst25 * fRec569[1]);
			double fTemp275 = (fConst26 * fRec572[1]);
			fRec574[0] = (fTemp273 + (fTemp274 + (fRec574[1] + fTemp275)));
			fRec572[0] = fRec574[0];
			double fRec573 = ((fTemp275 + fTemp274) + fTemp273);
			fRec571[0] = (fRec572[0] + fRec571[1]);
			fRec569[0] = fRec571[0];
			double fRec570 = fRec573;
			fVec11[(IOTA & 1023)] = ((49383507080000.0 * fTemp58) + (fRec531 + (fRec546 + (fRec558 + (fRec567 + fRec570)))));
			output11[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec11[((IOTA - iConst33) & 1023)])));
			double fTemp276 = (fConst3 * fRec575[1]);
			double fTemp277 = (fConst6 * fRec578[1]);
			double fTemp278 = (fConst7 * fRec581[1]);
			double fTemp279 = (fConst9 * (((2496831983000.0 * fTemp10) + ((94907580440000.0 * fTemp14) + ((65440813180000.0 * fTemp13) + (67325885410000.0 * fTemp11)))) - ((((50500814330000.0 * fTemp12) + (12615851790000.0 * fTemp16)) + (139496784200000.0 * fTemp15)) + (18096479640000.0 * fTemp17))));
			double fTemp280 = (fConst11 * fRec584[1]);
			double fTemp281 = (fConst12 * fRec587[1]);
			fRec589[0] = (fTemp279 + (fTemp280 + (fRec589[1] + fTemp281)));
			fRec587[0] = fRec589[0];
			double fRec588 = ((fTemp281 + fTemp280) + fTemp279);
			fRec586[0] = (fRec587[0] + fRec586[1]);
			fRec584[0] = fRec586[0];
			double fRec585 = fRec588;
			fRec583[0] = (fTemp277 + (fTemp278 + (fRec585 + fRec583[1])));
			fRec581[0] = fRec583[0];
			double fRec582 = (fTemp277 + (fRec585 + fTemp278));
			fRec580[0] = (fRec581[0] + fRec580[1]);
			fRec578[0] = fRec580[0];
			double fRec579 = fRec582;
			fRec577[0] = (fTemp276 + (fRec579 + fRec577[1]));
			fRec575[0] = fRec577[0];
			double fRec576 = (fRec579 + fTemp276);
			double fTemp282 = (fConst22 * fRec590[1]);
			double fTemp283 = (fConst21 * fRec593[1]);
			double fTemp284 = (fConst18 * (((50529692620000.0 * fTemp27) + ((40644620640000.0 * fTemp33) + ((180346773100000.0 * fTemp32) + ((4108120367000.0 * fTemp28) + (234923037400000.0 * fTemp29))))) - ((69524715830000.0 * fTemp31) + ((52887796840000.0 * fTemp26) + (156669155100000.0 * fTemp30)))));
			double fTemp285 = (fConst20 * fRec596[1]);
			double fTemp286 = (fConst19 * fRec599[1]);
			fRec601[0] = (fTemp284 + (fTemp285 + (fRec601[1] + fTemp286)));
			fRec599[0] = fRec601[0];
			double fRec600 = ((fTemp286 + fTemp285) + fTemp284);
			fRec598[0] = (fRec599[0] + fRec598[1]);
			fRec596[0] = fRec598[0];
			double fRec597 = fRec600;
			fRec595[0] = (fTemp282 + (fTemp283 + (fRec597 + fRec595[1])));
			fRec593[0] = fRec595[0];
			double fRec594 = (fTemp282 + (fRec597 + fTemp283));
			fRec592[0] = (fRec593[0] + fRec592[1]);
			fRec590[0] = fRec592[0];
			double fRec591 = fRec594;
			double fTemp287 = (fConst30 * (((180353656200000.0 * fTemp52) + (((144028857200000.0 * fTemp53) + (4875953183000.0 * fTemp54)) + (19187575080000.0 * fTemp50))) - (((138293434400000.0 * fTemp48) + (17743906560000.0 * fTemp49)) + (240309920000000.0 * fTemp51))));
			double fTemp288 = (fConst32 * fRec608[1]);
			double fTemp289 = (fConst31 * fRec605[1]);
			fRec610[0] = (((fTemp287 + fRec610[1]) + fTemp288) + fTemp289);
			fRec608[0] = fRec610[0];
			double fRec609 = ((fTemp287 + fTemp288) + fTemp289);
			fRec607[0] = (fRec608[0] + fRec607[1]);
			fRec605[0] = fRec607[0];
			double fRec606 = fRec609;
			double fTemp290 = (fConst28 * fRec602[1]);
			fRec604[0] = ((fRec606 + fRec604[1]) + fTemp290);
			fRec602[0] = fRec604[0];
			double fRec603 = (fRec606 + fTemp290);
			double fTemp291 = (fConst14 * (((170594824400000.0 * fTemp23) + (18803148500000.0 * fTemp21)) - (24813917340000.0 * fTemp22)));
			double fTemp292 = (fConst15 * fRec611[1]);
			fRec613[0] = (fTemp291 + (fRec613[1] + fTemp292));
			fRec611[0] = fRec613[0];
			double fRec612 = (fTemp292 + fTemp291);
			double fTemp293 = (fConst24 * (((10568051970000.0 * fTemp43) + (207584688200000.0 * fTemp40)) - ((30857688130000.0 * fTemp42) + ((206060398900000.0 * fTemp39) + (38094937620000.0 * fTemp41)))));
			double fTemp294 = (fConst25 * fRec614[1]);
			double fTemp295 = (fConst26 * fRec617[1]);
			fRec619[0] = (fTemp293 + (fTemp294 + (fRec619[1] + fTemp295)));
			fRec617[0] = fRec619[0];
			double fRec618 = ((fTemp295 + fTemp294) + fTemp293);
			fRec616[0] = (fRec617[0] + fRec616[1]);
			fRec614[0] = fRec616[0];
			double fRec615 = fRec618;
			fVec12[(IOTA & 1023)] = ((fRec576 + (fRec591 + (fRec603 + (fRec612 + fRec615)))) + (21200170750000.0 * fTemp58));
			output12[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec12[((IOTA - iConst33) & 1023)])));
			double fTemp296 = (fConst3 * fRec620[1]);
			double fTemp297 = (fConst6 * fRec623[1]);
			double fTemp298 = (fConst7 * fRec626[1]);
			double fTemp299 = (fConst9 * (((((40538617910000.0 * fTemp12) + (11339413180000.0 * fTemp16)) + (179875313200000.0 * fTemp15)) + (7001278591000.0 * fTemp13)) - ((53894580020000.0 * fTemp10) + ((44977594080000.0 * fTemp17) + ((187905138500000.0 * fTemp14) + (90417799130000.0 * fTemp11))))));
			double fTemp300 = (fConst11 * fRec629[1]);
			double fTemp301 = (fConst12 * fRec632[1]);
			fRec634[0] = (fTemp299 + (fTemp300 + (fRec634[1] + fTemp301)));
			fRec632[0] = fRec634[0];
			double fRec633 = ((fTemp301 + fTemp300) + fTemp299);
			fRec631[0] = (fRec632[0] + fRec631[1]);
			fRec629[0] = fRec631[0];
			double fRec630 = fRec633;
			fRec628[0] = (fTemp297 + (fTemp298 + (fRec630 + fRec628[1])));
			fRec626[0] = fRec628[0];
			double fRec627 = (fTemp297 + (fRec630 + fTemp298));
			fRec625[0] = (fRec626[0] + fRec625[1]);
			fRec623[0] = fRec625[0];
			double fRec624 = fRec627;
			fRec622[0] = (fTemp296 + (fRec624 + fRec622[1]));
			fRec620[0] = fRec622[0];
			double fRec621 = (fRec624 + fTemp296);
			double fTemp302 = (fConst14 * (0.0 - (((58545565250000.0 * fTemp23) + (55112727820000.0 * fTemp21)) + (65489309510000.0 * fTemp22))));
			double fTemp303 = (fConst15 * fRec635[1]);
			fRec637[0] = (fTemp302 + (fRec637[1] + fTemp303));
			fRec635[0] = fRec637[0];
			double fRec636 = (fTemp303 + fTemp302);
			double fTemp304 = (fConst24 * ((((99397858000000.0 * fTemp42) + ((161734564200000.0 * fTemp39) + (2932811138000.0 * fTemp41))) + (77111526960000.0 * fTemp43)) - (229498236400000.0 * fTemp40)));
			double fTemp305 = (fConst25 * fRec638[1]);
			double fTemp306 = (fConst26 * fRec641[1]);
			fRec643[0] = (fTemp304 + (fTemp305 + (fRec643[1] + fTemp306)));
			fRec641[0] = fRec643[0];
			double fRec642 = ((fTemp306 + fTemp305) + fTemp304);
			fRec640[0] = (fRec641[0] + fRec640[1]);
			fRec638[0] = fRec640[0];
			double fRec639 = fRec642;
			double fTemp307 = (fConst28 * fRec644[1]);
			double fTemp308 = (fConst30 * ((((114958171000000.0 * fTemp48) + (5181053920000.0 * fTemp54)) + (220250201700000.0 * fTemp51)) - ((((176688092800000.0 * fTemp49) + (173714723100000.0 * fTemp53)) + (73485739130000.0 * fTemp50)) + (144382966600000.0 * fTemp52))));
			double fTemp309 = (fConst31 * fRec647[1]);
			double fTemp310 = (fConst32 * fRec650[1]);
			fRec652[0] = (fTemp308 + (fTemp309 + (fRec652[1] + fTemp310)));
			fRec650[0] = fRec652[0];
			double fRec651 = ((fTemp310 + fTemp309) + fTemp308);
			fRec649[0] = (fRec650[0] + fRec649[1]);
			fRec647[0] = fRec649[0];
			double fRec648 = fRec651;
			fRec646[0] = (fTemp307 + (fRec648 + fRec646[1]));
			fRec644[0] = fRec646[0];
			double fRec645 = (fRec648 + fTemp307);
			double fTemp311 = (fConst22 * fRec653[1]);
			double fTemp312 = (fConst21 * fRec656[1]);
			double fTemp313 = (fConst18 * (((30845579960000.0 * fTemp27) + ((162841924100000.0 * fTemp33) + ((95558391500000.0 * fTemp31) + (((39322054360000.0 * fTemp26) + (18052043870000.0 * fTemp28)) + (190116307300000.0 * fTemp30))))) - ((200442030300000.0 * fTemp32) + (164968270900000.0 * fTemp29))));
			double fTemp314 = (fConst20 * fRec659[1]);
			double fTemp315 = (fConst19 * fRec662[1]);
			fRec664[0] = (fTemp313 + (fTemp314 + (fRec664[1] + fTemp315)));
			fRec662[0] = fRec664[0];
			double fRec663 = ((fTemp315 + fTemp314) + fTemp313);
			fRec661[0] = (fRec662[0] + fRec661[1]);
			fRec659[0] = fRec661[0];
			double fRec660 = fRec663;
			fRec658[0] = (fTemp311 + (fTemp312 + (fRec660 + fRec658[1])));
			fRec656[0] = fRec658[0];
			double fRec657 = (fTemp311 + (fRec660 + fTemp312));
			fRec655[0] = (fRec656[0] + fRec655[1]);
			fRec653[0] = fRec655[0];
			double fRec654 = fRec657;
			fVec13[(IOTA & 1023)] = (((((fRec621 + fRec636) + fRec639) + fRec645) + fRec654) + (53813457130000.0 * fTemp58));
			output13[i] = FAUSTFLOAT((0.82673893405600718 * (fVec13[((IOTA - iConst33) & 1023)] * fRec0[0])));
			double fTemp316 = (fConst14 * (((85757114720000.0 * fTemp23) + (76461579490000.0 * fTemp21)) + (121843103100000.0 * fTemp22)));
			double fTemp317 = (fConst15 * fRec665[1]);
			fRec667[0] = (fTemp316 + (fRec667[1] + fTemp317));
			fRec665[0] = fRec667[0];
			double fRec666 = (fTemp317 + fTemp316);
			double fTemp318 = (fConst6 * fRec671[1]);
			double fTemp319 = (fConst7 * fRec674[1]);
			double fTemp320 = (fConst9 * (((91845634170000.0 * fTemp10) + ((48348055370000.0 * fTemp17) + ((198035797400000.0 * fTemp14) + ((22321691460000.0 * fTemp13) + ((30136170810000.0 * fTemp12) + (204466583100000.0 * fTemp11)))))) - ((12322110540000.0 * fTemp16) + (70815976180000.0 * fTemp15))));
			double fTemp321 = (fConst11 * fRec677[1]);
			double fTemp322 = (fConst12 * fRec680[1]);
			fRec682[0] = (fTemp320 + (fTemp321 + (fRec682[1] + fTemp322)));
			fRec680[0] = fRec682[0];
			double fRec681 = ((fTemp322 + fTemp321) + fTemp320);
			fRec679[0] = (fRec680[0] + fRec679[1]);
			fRec677[0] = fRec679[0];
			double fRec678 = fRec681;
			fRec676[0] = (fTemp318 + (fTemp319 + (fRec678 + fRec676[1])));
			fRec674[0] = fRec676[0];
			double fRec675 = (fTemp318 + (fRec678 + fTemp319));
			fRec673[0] = (fRec674[0] + fRec673[1]);
			fRec671[0] = fRec673[0];
			double fRec672 = fRec675;
			double fTemp323 = (fConst3 * fRec668[1]);
			fRec670[0] = ((fRec672 + fRec670[1]) + fTemp323);
			fRec668[0] = fRec670[0];
			double fRec669 = (fRec672 + fTemp323);
			double fTemp324 = (fConst24 * ((74765301230000.0 * fTemp40) - (((162469869100000.0 * fTemp42) + ((51704816560000.0 * fTemp39) + (60047011060000.0 * fTemp41))) + (165159683200000.0 * fTemp43))));
			double fTemp325 = (fConst25 * fRec683[1]);
			double fTemp326 = (fConst26 * fRec686[1]);
			fRec688[0] = (fTemp324 + (fTemp325 + (fRec688[1] + fTemp326)));
			fRec686[0] = fRec688[0];
			double fRec687 = ((fTemp326 + fTemp325) + fTemp324);
			fRec685[0] = (fRec686[0] + fRec685[1]);
			fRec683[0] = fRec685[0];
			double fRec684 = fRec687;
			double fTemp327 = (fConst30 * (((136150538700000.0 * fTemp52) + (((267994836700000.0 * fTemp49) + (28981730760000.0 * fTemp53)) + (146694251900000.0 * fTemp50))) - (((124737204100000.0 * fTemp48) + (9378315149000.0 * fTemp54)) + (139123247500000.0 * fTemp51))));
			double fTemp328 = (fConst32 * fRec695[1]);
			double fTemp329 = (fConst31 * fRec692[1]);
			fRec697[0] = (((fTemp327 + fRec697[1]) + fTemp328) + fTemp329);
			fRec695[0] = fRec697[0];
			double fRec696 = ((fTemp327 + fTemp328) + fTemp329);
			fRec694[0] = (fRec695[0] + fRec694[1]);
			fRec692[0] = fRec694[0];
			double fRec693 = fRec696;
			double fTemp330 = (fConst28 * fRec689[1]);
			fRec691[0] = ((fRec693 + fRec691[1]) + fTemp330);
			fRec689[0] = fRec691[0];
			double fRec690 = (fRec693 + fTemp330);
			double fTemp331 = (fConst22 * fRec698[1]);
			double fTemp332 = (fConst21 * fRec701[1]);
			double fTemp333 = (fConst18 * (((73502326770000.0 * fTemp32) + (148652976800000.0 * fTemp29)) - ((35334535370000.0 * fTemp27) + ((256438085300000.0 * fTemp33) + ((53914819580000.0 * fTemp31) + (((23879451150000.0 * fTemp26) + (43514524640000.0 * fTemp28)) + (169373357200000.0 * fTemp30)))))));
			double fTemp334 = (fConst20 * fRec704[1]);
			double fTemp335 = (fConst19 * fRec707[1]);
			fRec709[0] = (fTemp333 + (fTemp334 + (fRec709[1] + fTemp335)));
			fRec707[0] = fRec709[0];
			double fRec708 = ((fTemp335 + fTemp334) + fTemp333);
			fRec706[0] = (fRec707[0] + fRec706[1]);
			fRec704[0] = fRec706[0];
			double fRec705 = fRec708;
			fRec703[0] = (fTemp331 + (fTemp332 + (fRec705 + fRec703[1])));
			fRec701[0] = fRec703[0];
			double fRec702 = (fTemp331 + (fRec705 + fTemp332));
			fRec700[0] = (fRec701[0] + fRec700[1]);
			fRec698[0] = fRec700[0];
			double fRec699 = fRec702;
			fVec14[(IOTA & 1023)] = (((fRec666 + (fRec669 + (fRec684 + fRec690))) + fRec699) - (344980309600.0 * fTemp58));
			output14[i] = FAUSTFLOAT((0.82673893405600718 * (fVec14[((IOTA - iConst33) & 1023)] * fRec0[0])));
			double fTemp336 = (fConst22 * fRec710[1]);
			double fTemp337 = (fConst21 * fRec713[1]);
			double fTemp338 = (fConst18 * (((166746513500000.0 * fTemp33) + ((20039843820000.0 * fTemp32) + ((64065590990000.0 * fTemp31) + (((7049328569000.0 * fTemp26) + (61002282620000.0 * fTemp28)) + (122344650100000.0 * fTemp30))))) - ((45347328730000.0 * fTemp27) + (22519161100000.0 * fTemp29))));
			double fTemp339 = (fConst20 * fRec716[1]);
			double fTemp340 = (fConst19 * fRec719[1]);
			fRec721[0] = (fTemp338 + (fTemp339 + (fRec721[1] + fTemp340)));
			fRec719[0] = fRec721[0];
			double fRec720 = ((fTemp340 + fTemp339) + fTemp338);
			fRec718[0] = (fRec719[0] + fRec718[1]);
			fRec716[0] = fRec718[0];
			double fRec717 = fRec720;
			fRec715[0] = (fTemp336 + (fTemp337 + (fRec717 + fRec715[1])));
			fRec713[0] = fRec715[0];
			double fRec714 = (fTemp336 + (fRec717 + fTemp337));
			fRec712[0] = (fRec713[0] + fRec712[1]);
			fRec710[0] = fRec712[0];
			double fRec711 = fRec714;
			double fTemp341 = (fConst3 * fRec722[1]);
			double fTemp342 = (fConst6 * fRec725[1]);
			double fTemp343 = (fConst7 * fRec728[1]);
			double fTemp344 = (fConst9 * ((((21184423730000.0 * fTemp16) + (20701031620000.0 * fTemp15)) + (1500831221000.0 * fTemp17)) - ((85156954170000.0 * fTemp10) + ((101321166900000.0 * fTemp14) + ((37187505620000.0 * fTemp13) + ((57452289630000.0 * fTemp12) + (235844841100000.0 * fTemp11)))))));
			double fTemp345 = (fConst11 * fRec731[1]);
			double fTemp346 = (fConst12 * fRec734[1]);
			fRec736[0] = (fTemp344 + (fTemp345 + (fRec736[1] + fTemp346)));
			fRec734[0] = fRec736[0];
			double fRec735 = ((fTemp346 + fTemp345) + fTemp344);
			fRec733[0] = (fRec734[0] + fRec733[1]);
			fRec731[0] = fRec733[0];
			double fRec732 = fRec735;
			fRec730[0] = (fTemp342 + (fTemp343 + (fRec732 + fRec730[1])));
			fRec728[0] = fRec730[0];
			double fRec729 = (fTemp342 + (fRec732 + fTemp343));
			fRec727[0] = (fRec728[0] + fRec727[1]);
			fRec725[0] = fRec727[0];
			double fRec726 = fRec729;
			fRec724[0] = (fTemp341 + (fRec726 + fRec724[1]));
			fRec722[0] = fRec724[0];
			double fRec723 = (fRec726 + fTemp341);
			double fTemp347 = (fConst28 * fRec737[1]);
			double fTemp348 = (fConst30 * ((((24336120450000.0 * fTemp48) + (21111905200000.0 * fTemp54)) + (45571128390000.0 * fTemp51)) - ((((210042551700000.0 * fTemp49) + (17712844040000.0 * fTemp53)) + (203852133100000.0 * fTemp50)) + (170160173000000.0 * fTemp52))));
			double fTemp349 = (fConst31 * fRec740[1]);
			double fTemp350 = (fConst32 * fRec743[1]);
			fRec745[0] = (fTemp348 + (fTemp349 + (fRec745[1] + fTemp350)));
			fRec743[0] = fRec745[0];
			double fRec744 = ((fTemp350 + fTemp349) + fTemp348);
			fRec742[0] = (fRec743[0] + fRec742[1]);
			fRec740[0] = fRec742[0];
			double fRec741 = fRec744;
			fRec739[0] = (fTemp347 + (fRec741 + fRec739[1]));
			fRec737[0] = fRec739[0];
			double fRec738 = (fRec741 + fTemp347);
			double fTemp351 = (fConst14 * ((60947518460000.0 * fTemp23) - ((111678475200000.0 * fTemp21) + (106148277200000.0 * fTemp22))));
			double fTemp352 = (fConst15 * fRec746[1]);
			fRec748[0] = (fTemp351 + (fRec748[1] + fTemp352));
			fRec746[0] = fRec748[0];
			double fRec747 = (fTemp352 + fTemp351);
			double fTemp353 = (fConst24 * ((((192919716300000.0 * fTemp42) + (22462987280000.0 * fTemp41)) + (207079751500000.0 * fTemp43)) - ((49181470130000.0 * fTemp39) + (69018861540000.0 * fTemp40))));
			double fTemp354 = (fConst25 * fRec749[1]);
			double fTemp355 = (fConst26 * fRec752[1]);
			fRec754[0] = (fTemp353 + (fTemp354 + (fRec754[1] + fTemp355)));
			fRec752[0] = fRec754[0];
			double fRec753 = ((fTemp355 + fTemp354) + fTemp353);
			fRec751[0] = (fRec752[0] + fRec751[1]);
			fRec749[0] = fRec751[0];
			double fRec750 = fRec753;
			fVec15[(IOTA & 1023)] = ((74890038210000.0 * fTemp58) + (fRec711 + (fRec723 + (fRec738 + (fRec747 + fRec750)))));
			output15[i] = FAUSTFLOAT((0.82673893405600718 * (fRec0[0] * fVec15[((IOTA - iConst33) & 1023)])));
			double fTemp356 = (fConst35 * (((((15223580520000.0 * fTemp42) + (14558656790000.0 * fTemp39)) + (52231196370000.0 * fTemp43)) + (21199839460000.0 * fTemp40)) - (1290106341000.0 * fTemp41)));
			double fTemp357 = (fConst36 * fRec755[1]);
			double fTemp358 = (fConst37 * fRec758[1]);
			fRec760[0] = (fTemp356 + (fTemp357 + (fRec760[1] + fTemp358)));
			fRec758[0] = fRec760[0];
			double fRec759 = ((fTemp358 + fTemp357) + fTemp356);
			fRec757[0] = (fRec758[0] + fRec757[1]);
			fRec755[0] = fRec757[0];
			double fRec756 = fRec759;
			double fTemp359 = (fConst39 * (((7361209204000.0 * fTemp23) + (35783153540000.0 * fTemp21)) + (23022139230000.0 * fTemp22)));
			double fTemp360 = (fConst40 * fRec761[1]);
			fRec763[0] = (fTemp359 + (fRec763[1] + fTemp360));
			fRec761[0] = fRec763[0];
			double fRec762 = (fTemp360 + fTemp359);
			double fTemp361 = (fConst42 * fRec764[1]);
			double fTemp362 = (fConst44 * fRec767[1]);
			double fTemp363 = (fConst45 * fRec770[1]);
			double fTemp364 = (fConst47 * (((((19462424920000.0 * fTemp12) + (54877422880000.0 * fTemp16)) + (39849605930000.0 * fTemp15)) + (19910389680000.0 * fTemp14)) - ((29404079050000.0 * fTemp10) + ((9656029461000.0 * fTemp17) + ((20119372910000.0 * fTemp13) + (4483152171000.0 * fTemp11))))));
			double fTemp365 = (fConst48 * fRec773[1]);
			double fTemp366 = (fConst49 * fRec776[1]);
			fRec778[0] = (fTemp364 + (fTemp365 + (fRec778[1] + fTemp366)));
			fRec776[0] = fRec778[0];
			double fRec777 = ((fTemp366 + fTemp365) + fTemp364);
			fRec775[0] = (fRec776[0] + fRec775[1]);
			fRec773[0] = fRec775[0];
			double fRec774 = fRec777;
			fRec772[0] = (fTemp362 + (fTemp363 + (fRec774 + fRec772[1])));
			fRec770[0] = fRec772[0];
			double fRec771 = (fTemp362 + (fRec774 + fTemp363));
			fRec769[0] = (fRec770[0] + fRec769[1]);
			fRec767[0] = fRec769[0];
			double fRec768 = fRec771;
			fRec766[0] = (fTemp361 + (fRec768 + fRec766[1]));
			fRec764[0] = fRec766[0];
			double fRec765 = (fRec768 + fTemp361);
			double fTemp367 = (fConst51 * fRec779[1]);
			double fTemp368 = (fConst53 * (((11024580120000.0 * fTemp52) + ((47049245490000.0 * fTemp51) + ((((25522995670000.0 * fTemp48) + (37824098020000.0 * fTemp49)) + (4499586858000.0 * fTemp53)) + (27242734920000.0 * fTemp50)))) - (43475947650000.0 * fTemp54)));
			double fTemp369 = (fConst54 * fRec782[1]);
			double fTemp370 = (fConst55 * fRec785[1]);
			fRec787[0] = (fTemp368 + (fTemp369 + (fRec787[1] + fTemp370)));
			fRec785[0] = fRec787[0];
			double fRec786 = ((fTemp370 + fTemp369) + fTemp368);
			fRec784[0] = (fRec785[0] + fRec784[1]);
			fRec782[0] = fRec784[0];
			double fRec783 = fRec786;
			fRec781[0] = (fTemp367 + (fRec783 + fRec781[1]));
			fRec779[0] = fRec781[0];
			double fRec780 = (fRec783 + fTemp367);
			double fTemp371 = (fConst57 * fRec788[1]);
			double fTemp372 = (fConst58 * fRec791[1]);
			double fTemp373 = (fConst60 * (((8094999980000.0 * fTemp27) + ((24882567620000.0 * fTemp33) + ((52338762530000.0 * fTemp32) + ((915490613600.0 * fTemp31) + ((34630294770000.0 * fTemp29) + (23268203920000.0 * fTemp30)))))) - ((20907834690000.0 * fTemp26) + (51606315620000.0 * fTemp28))));
			double fTemp374 = (fConst61 * fRec794[1]);
			double fTemp375 = (fConst62 * fRec797[1]);
			fRec799[0] = (fTemp373 + (fTemp374 + (fRec799[1] + fTemp375)));
			fRec797[0] = fRec799[0];
			double fRec798 = ((fTemp375 + fTemp374) + fTemp373);
			fRec796[0] = (fRec797[0] + fRec796[1]);
			fRec794[0] = fRec796[0];
			double fRec795 = fRec798;
			fRec793[0] = (fTemp371 + (fTemp372 + (fRec795 + fRec793[1])));
			fRec791[0] = fRec793[0];
			double fRec792 = (fTemp371 + (fRec795 + fTemp372));
			fRec790[0] = (fRec791[0] + fRec790[1]);
			fRec788[0] = fRec790[0];
			double fRec789 = fRec792;
			fVec16[(IOTA & 1023)] = ((16626118110000.0 * fTemp58) + (fRec756 + (fRec762 + (fRec765 + (fRec780 + fRec789)))));
			output16[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec16[((IOTA - iConst63) & 1023)])));
			double fTemp376 = (fConst57 * fRec800[1]);
			double fTemp377 = (fConst58 * fRec803[1]);
			double fTemp378 = (fConst60 * (((4331231686000.0 * fTemp30) + ((29342825980000.0 * fTemp26) + (26955986710000.0 * fTemp29))) - ((3795989639000.0 * fTemp27) + ((29255853110000.0 * fTemp33) + ((58335182400000.0 * fTemp32) + ((47707254820000.0 * fTemp28) + (6003681589000.0 * fTemp31)))))));
			double fTemp379 = (fConst61 * fRec806[1]);
			double fTemp380 = (fConst62 * fRec809[1]);
			fRec811[0] = (fTemp378 + (fTemp379 + (fRec811[1] + fTemp380)));
			fRec809[0] = fRec811[0];
			double fRec810 = ((fTemp380 + fTemp379) + fTemp378);
			fRec808[0] = (fRec809[0] + fRec808[1]);
			fRec806[0] = fRec808[0];
			double fRec807 = fRec810;
			fRec805[0] = (fTemp376 + (fTemp377 + (fRec807 + fRec805[1])));
			fRec803[0] = fRec805[0];
			double fRec804 = (fTemp376 + (fRec807 + fTemp377));
			fRec802[0] = (fRec803[0] + fRec802[1]);
			fRec800[0] = fRec802[0];
			double fRec801 = fRec804;
			double fTemp381 = (fConst42 * fRec812[1]);
			double fTemp382 = (fConst44 * fRec815[1]);
			double fTemp383 = (fConst45 * fRec818[1]);
			double fTemp384 = (fConst47 * (((34609541570000.0 * fTemp10) + (8282445346000.0 * fTemp14)) - ((22778446780000.0 * fTemp17) + ((14294926170000.0 * fTemp13) + ((44582137050000.0 * fTemp15) + ((50626505690000.0 * fTemp16) + ((4934309498000.0 * fTemp12) + (36472416030000.0 * fTemp11))))))));
			double fTemp385 = (fConst48 * fRec821[1]);
			double fTemp386 = (fConst49 * fRec824[1]);
			fRec826[0] = (fTemp384 + (fTemp385 + (fRec826[1] + fTemp386)));
			fRec824[0] = fRec826[0];
			double fRec825 = ((fTemp386 + fTemp385) + fTemp384);
			fRec823[0] = (fRec824[0] + fRec823[1]);
			fRec821[0] = fRec823[0];
			double fRec822 = fRec825;
			fRec820[0] = (fTemp382 + (fTemp383 + (fRec822 + fRec820[1])));
			fRec818[0] = fRec820[0];
			double fRec819 = (fTemp382 + (fRec822 + fTemp383));
			fRec817[0] = (fRec818[0] + fRec817[1]);
			fRec815[0] = fRec817[0];
			double fRec816 = fRec819;
			fRec814[0] = (fTemp381 + (fRec816 + fRec814[1]));
			fRec812[0] = fRec814[0];
			double fRec813 = (fRec816 + fTemp381);
			double fTemp387 = (fConst35 * (((46956389670000.0 * fTemp43) + (14083887420000.0 * fTemp40)) - ((18826775080000.0 * fTemp42) + ((21597263700000.0 * fTemp39) + (1882723509000.0 * fTemp41)))));
			double fTemp388 = (fConst36 * fRec827[1]);
			double fTemp389 = (fConst37 * fRec830[1]);
			fRec832[0] = (fTemp387 + (fTemp388 + (fRec832[1] + fTemp389)));
			fRec830[0] = fRec832[0];
			double fRec831 = ((fTemp389 + fTemp388) + fTemp387);
			fRec829[0] = (fRec830[0] + fRec829[1]);
			fRec827[0] = fRec829[0];
			double fRec828 = fRec831;
			double fTemp390 = (fConst51 * fRec833[1]);
			double fTemp391 = (fConst53 * (((24239692310000.0 * fTemp50) + (34652255210000.0 * fTemp51)) - (((((28085166330000.0 * fTemp48) + (45096912980000.0 * fTemp49)) + (8058672933000.0 * fTemp53)) + (42754517600000.0 * fTemp54)) + (1185239488000.0 * fTemp52))));
			double fTemp392 = (fConst54 * fRec836[1]);
			double fTemp393 = (fConst55 * fRec839[1]);
			fRec841[0] = (fTemp391 + (fTemp392 + (fRec841[1] + fTemp393)));
			fRec839[0] = fRec841[0];
			double fRec840 = ((fTemp393 + fTemp392) + fTemp391);
			fRec838[0] = (fRec839[0] + fRec838[1]);
			fRec836[0] = fRec838[0];
			double fRec837 = fRec840;
			fRec835[0] = (fTemp390 + (fRec837 + fRec835[1]));
			fRec833[0] = fRec835[0];
			double fRec834 = (fRec837 + fTemp390);
			double fTemp394 = (fConst39 * (((35699596440000.0 * fTemp21) + (20385436550000.0 * fTemp22)) - (9879416551000.0 * fTemp23)));
			double fTemp395 = (fConst40 * fRec842[1]);
			fRec844[0] = (fTemp394 + (fRec844[1] + fTemp395));
			fRec842[0] = fRec844[0];
			double fRec843 = (fTemp395 + fTemp394);
			fVec17[(IOTA & 1023)] = ((15815513250000.0 * fTemp58) + (fRec801 + (fRec813 + (fRec828 + (fRec834 + fRec843)))));
			output17[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec17[((IOTA - iConst63) & 1023)])));
			double fTemp396 = (fConst42 * fRec845[1]);
			double fTemp397 = (fConst44 * fRec848[1]);
			double fTemp398 = (fConst45 * fRec851[1]);
			double fTemp399 = (fConst47 * (((25723939010000.0 * fTemp10) + ((19618984620000.0 * fTemp17) + ((20678621090000.0 * fTemp13) + ((27668314740000.0 * fTemp15) + ((61909348340000.0 * fTemp16) + ((5236636122000.0 * fTemp12) + (3979021100000.0 * fTemp11))))))) - (42114829970000.0 * fTemp14)));
			double fTemp400 = (fConst48 * fRec854[1]);
			double fTemp401 = (fConst49 * fRec857[1]);
			fRec859[0] = (fTemp399 + (fTemp400 + (fRec859[1] + fTemp401)));
			fRec857[0] = fRec859[0];
			double fRec858 = ((fTemp401 + fTemp400) + fTemp399);
			fRec856[0] = (fRec857[0] + fRec856[1]);
			fRec854[0] = fRec856[0];
			double fRec855 = fRec858;
			fRec853[0] = (fTemp397 + (fTemp398 + (fRec855 + fRec853[1])));
			fRec851[0] = fRec853[0];
			double fRec852 = (fTemp397 + (fRec855 + fTemp398));
			fRec850[0] = (fRec851[0] + fRec850[1]);
			fRec848[0] = fRec850[0];
			double fRec849 = fRec852;
			fRec847[0] = (fTemp396 + (fRec849 + fRec847[1]));
			fRec845[0] = fRec847[0];
			double fRec846 = (fRec849 + fTemp396);
			double fTemp402 = (fConst57 * fRec860[1]);
			double fTemp403 = (fConst58 * fRec863[1]);
			double fTemp404 = (fConst60 * (((4895345212000.0 * fTemp27) + ((31841987880000.0 * fTemp32) + ((46772112680000.0 * fTemp26) + (1789920197000.0 * fTemp31)))) - ((21719082910000.0 * fTemp33) + ((53590226850000.0 * fTemp30) + ((19236985330000.0 * fTemp28) + (35482147310000.0 * fTemp29))))));
			double fTemp405 = (fConst61 * fRec866[1]);
			double fTemp406 = (fConst62 * fRec869[1]);
			fRec871[0] = (fTemp404 + (fTemp405 + (fRec871[1] + fTemp406)));
			fRec869[0] = fRec871[0];
			double fRec870 = ((fTemp406 + fTemp405) + fTemp404);
			fRec868[0] = (fRec869[0] + fRec868[1]);
			fRec866[0] = fRec868[0];
			double fRec867 = fRec870;
			fRec865[0] = (fTemp402 + (fTemp403 + (fRec867 + fRec865[1])));
			fRec863[0] = fRec865[0];
			double fRec864 = (fTemp402 + (fRec867 + fTemp403));
			fRec862[0] = (fRec863[0] + fRec862[1]);
			fRec860[0] = fRec862[0];
			double fRec861 = fRec864;
			double fTemp407 = (fConst51 * fRec872[1]);
			double fTemp408 = (fConst53 * (((13925822790000.0 * fTemp48) + (3325998812000.0 * fTemp50)) - ((24946323250000.0 * fTemp52) + ((((33739936460000.0 * fTemp49) + (25299893750000.0 * fTemp53)) + (39844586250000.0 * fTemp54)) + (48299413560000.0 * fTemp51)))));
			double fTemp409 = (fConst54 * fRec875[1]);
			double fTemp410 = (fConst55 * fRec878[1]);
			fRec880[0] = (fTemp408 + (fTemp409 + (fRec880[1] + fTemp410)));
			fRec878[0] = fRec880[0];
			double fRec879 = ((fTemp410 + fTemp409) + fTemp408);
			fRec877[0] = (fRec878[0] + fRec877[1]);
			fRec875[0] = fRec877[0];
			double fRec876 = fRec879;
			fRec874[0] = (fTemp407 + (fRec876 + fRec874[1]));
			fRec872[0] = fRec874[0];
			double fRec873 = (fRec876 + fTemp407);
			double fTemp411 = (fConst39 * (((32189960290000.0 * fTemp21) + (6502448942000.0 * fTemp22)) - (23708847580000.0 * fTemp23)));
			double fTemp412 = (fConst40 * fRec881[1]);
			fRec883[0] = (fTemp411 + (fRec883[1] + fTemp412));
			fRec881[0] = fRec883[0];
			double fRec882 = (fTemp412 + fTemp411);
			double fTemp413 = (fConst35 * ((12557440000000.0 * fTemp43) - (((14357641120000.0 * fTemp42) + ((49577953130000.0 * fTemp39) + (1316220031000.0 * fTemp41))) + (21835225790000.0 * fTemp40))));
			double fTemp414 = (fConst36 * fRec884[1]);
			double fTemp415 = (fConst37 * fRec887[1]);
			fRec889[0] = (fTemp413 + (fTemp414 + (fRec889[1] + fTemp415)));
			fRec887[0] = fRec889[0];
			double fRec888 = ((fTemp415 + fTemp414) + fTemp413);
			fRec886[0] = (fRec887[0] + fRec886[1]);
			fRec884[0] = fRec886[0];
			double fRec885 = fRec888;
			fVec18[(IOTA & 1023)] = ((17297394620000.0 * fTemp58) + (fRec846 + (fRec861 + (fRec873 + (fRec882 + fRec885)))));
			output18[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec18[((IOTA - iConst63) & 1023)])));
			double fTemp416 = (fConst57 * fRec890[1]);
			double fTemp417 = (fConst58 * fRec893[1]);
			double fTemp418 = (fConst60 * (((28504754970000.0 * fTemp33) + ((14346638880000.0 * fTemp32) + (((49753422250000.0 * fTemp26) + (25936507530000.0 * fTemp28)) + (56612497610000.0 * fTemp30)))) - ((5527898542000.0 * fTemp27) + ((26474867020000.0 * fTemp29) + (1402883070000.0 * fTemp31)))));
			double fTemp419 = (fConst61 * fRec896[1]);
			double fTemp420 = (fConst62 * fRec899[1]);
			fRec901[0] = (fTemp418 + (fTemp419 + (fRec901[1] + fTemp420)));
			fRec899[0] = fRec901[0];
			double fRec900 = ((fTemp420 + fTemp419) + fTemp418);
			fRec898[0] = (fRec899[0] + fRec898[1]);
			fRec896[0] = fRec898[0];
			double fRec897 = fRec900;
			fRec895[0] = (fTemp416 + (fTemp417 + (fRec897 + fRec895[1])));
			fRec893[0] = fRec895[0];
			double fRec894 = (fTemp416 + (fRec897 + fTemp417));
			fRec892[0] = (fRec893[0] + fRec892[1]);
			fRec890[0] = fRec892[0];
			double fRec891 = fRec894;
			double fTemp421 = (fConst51 * fRec902[1]);
			double fTemp422 = (fConst53 * ((((6323667222000.0 * fTemp48) + (42894787920000.0 * fTemp49)) + (27255083740000.0 * fTemp52)) - ((((25150715310000.0 * fTemp53) + (43129991370000.0 * fTemp54)) + (6810740804000.0 * fTemp50)) + (37582230900000.0 * fTemp51))));
			double fTemp423 = (fConst54 * fRec905[1]);
			double fTemp424 = (fConst55 * fRec908[1]);
			fRec910[0] = (fTemp422 + (fTemp423 + (fRec910[1] + fTemp424)));
			fRec908[0] = fRec910[0];
			double fRec909 = ((fTemp424 + fTemp423) + fTemp422);
			fRec907[0] = (fRec908[0] + fRec907[1]);
			fRec905[0] = fRec907[0];
			double fRec906 = fRec909;
			fRec904[0] = (fTemp421 + (fRec906 + fRec904[1]));
			fRec902[0] = fRec904[0];
			double fRec903 = (fRec906 + fTemp421);
			double fTemp425 = (fConst35 * ((16884810920000.0 * fTemp42) - ((((49552383480000.0 * fTemp39) + (1699940537000.0 * fTemp41)) + (18535496420000.0 * fTemp43)) + (18186562490000.0 * fTemp40))));
			double fTemp426 = (fConst36 * fRec911[1]);
			double fTemp427 = (fConst37 * fRec914[1]);
			fRec916[0] = (fTemp425 + (fTemp426 + (fRec916[1] + fTemp427)));
			fRec914[0] = fRec916[0];
			double fRec915 = ((fTemp427 + fTemp426) + fTemp425);
			fRec913[0] = (fRec914[0] + fRec913[1]);
			fRec911[0] = fRec913[0];
			double fRec912 = fRec915;
			double fTemp428 = (fConst39 * ((35542058460000.0 * fTemp21) - ((22386978870000.0 * fTemp23) + (8247050674000.0 * fTemp22))));
			double fTemp429 = (fConst40 * fRec917[1]);
			fRec919[0] = (fTemp428 + (fRec919[1] + fTemp429));
			fRec917[0] = fRec919[0];
			double fRec918 = (fTemp429 + fTemp428);
			double fTemp430 = (fConst42 * fRec920[1]);
			double fTemp431 = (fConst44 * fRec923[1]);
			double fTemp432 = (fConst45 * fRec926[1]);
			double fTemp433 = (fConst47 * (((43340638250000.0 * fTemp14) + (((14062025860000.0 * fTemp12) + (13314547060000.0 * fTemp15)) + (16499337540000.0 * fTemp13))) - ((33433453280000.0 * fTemp10) + ((15819617720000.0 * fTemp17) + ((59206493460000.0 * fTemp16) + (15813292090000.0 * fTemp11))))));
			double fTemp434 = (fConst48 * fRec929[1]);
			double fTemp435 = (fConst49 * fRec932[1]);
			fRec934[0] = (fTemp433 + (fTemp434 + (fRec934[1] + fTemp435)));
			fRec932[0] = fRec934[0];
			double fRec933 = ((fTemp435 + fTemp434) + fTemp433);
			fRec931[0] = (fRec932[0] + fRec931[1]);
			fRec929[0] = fRec931[0];
			double fRec930 = fRec933;
			fRec928[0] = (fTemp431 + (fTemp432 + (fRec930 + fRec928[1])));
			fRec926[0] = fRec928[0];
			double fRec927 = (fTemp431 + (fRec930 + fTemp432));
			fRec925[0] = (fRec926[0] + fRec925[1]);
			fRec923[0] = fRec925[0];
			double fRec924 = fRec927;
			fRec922[0] = (fTemp430 + (fRec924 + fRec922[1]));
			fRec920[0] = fRec922[0];
			double fRec921 = (fRec924 + fTemp430);
			fVec19[(IOTA & 1023)] = ((16689989200000.0 * fTemp58) + (fRec891 + (fRec903 + (fRec912 + (fRec918 + fRec921)))));
			output19[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec19[((IOTA - iConst63) & 1023)])));
			double fTemp436 = (fConst42 * fRec935[1]);
			double fTemp437 = (fConst44 * fRec938[1]);
			double fTemp438 = (fConst45 * fRec941[1]);
			double fTemp439 = (fConst47 * (((6796890719000.0 * fTemp17) + ((62037466100000.0 * fTemp16) + (634075038100.0 * fTemp11))) - ((27776253780000.0 * fTemp10) + ((((20116581370000.0 * fTemp12) + (40400260680000.0 * fTemp15)) + (19200601670000.0 * fTemp13)) + (22176522920000.0 * fTemp14)))));
			double fTemp440 = (fConst48 * fRec944[1]);
			double fTemp441 = (fConst49 * fRec947[1]);
			fRec949[0] = (fTemp439 + (fTemp440 + (fRec949[1] + fTemp441)));
			fRec947[0] = fRec949[0];
			double fRec948 = ((fTemp441 + fTemp440) + fTemp439);
			fRec946[0] = (fRec947[0] + fRec946[1]);
			fRec944[0] = fRec946[0];
			double fRec945 = fRec948;
			fRec943[0] = (fTemp437 + (fTemp438 + (fRec945 + fRec943[1])));
			fRec941[0] = fRec943[0];
			double fRec942 = (fTemp437 + (fRec945 + fTemp438));
			fRec940[0] = (fRec941[0] + fRec940[1]);
			fRec938[0] = fRec940[0];
			double fRec939 = fRec942;
			fRec937[0] = (fTemp436 + (fRec939 + fRec937[1]));
			fRec935[0] = fRec937[0];
			double fRec936 = (fRec939 + fTemp436);
			double fTemp442 = (fConst57 * fRec950[1]);
			double fTemp443 = (fConst58 * fRec953[1]);
			double fTemp444 = (fConst60 * (((5567107191000.0 * fTemp27) + ((23226150370000.0 * fTemp33) + (((31035190480000.0 * fTemp29) + ((21002124650000.0 * fTemp26) + (50078795110000.0 * fTemp28))) + (1877224737000.0 * fTemp31)))) - ((52664935880000.0 * fTemp32) + (26019495850000.0 * fTemp30))));
			double fTemp445 = (fConst61 * fRec956[1]);
			double fTemp446 = (fConst62 * fRec959[1]);
			fRec961[0] = (fTemp444 + (fTemp445 + (fRec961[1] + fTemp446)));
			fRec959[0] = fRec961[0];
			double fRec960 = ((fTemp446 + fTemp445) + fTemp444);
			fRec958[0] = (fRec959[0] + fRec958[1]);
			fRec956[0] = fRec958[0];
			double fRec957 = fRec960;
			fRec955[0] = (fTemp442 + (fTemp443 + (fRec957 + fRec955[1])));
			fRec953[0] = fRec955[0];
			double fRec954 = (fTemp442 + (fRec957 + fTemp443));
			fRec952[0] = (fRec953[0] + fRec952[1]);
			fRec950[0] = fRec952[0];
			double fRec951 = fRec954;
			double fTemp447 = (fConst35 * (((14930839370000.0 * fTemp42) + (21070027880000.0 * fTemp40)) - (((14308460670000.0 * fTemp39) + (1125770313000.0 * fTemp41)) + (51302508680000.0 * fTemp43))));
			double fTemp448 = (fConst36 * fRec962[1]);
			double fTemp449 = (fConst37 * fRec965[1]);
			fRec967[0] = (fTemp447 + (fTemp448 + (fRec967[1] + fTemp449)));
			fRec965[0] = fRec967[0];
			double fRec966 = ((fTemp449 + fTemp448) + fTemp447);
			fRec964[0] = (fRec965[0] + fRec964[1]);
			fRec962[0] = fRec964[0];
			double fRec963 = fRec966;
			double fTemp450 = (fConst51 * fRec968[1]);
			double fTemp451 = (fConst53 * (((35872643850000.0 * fTemp49) + (43852725470000.0 * fTemp51)) - (((((25375789120000.0 * fTemp48) + (4655727748000.0 * fTemp53)) + (44091706760000.0 * fTemp54)) + (26378761340000.0 * fTemp50)) + (12168038100000.0 * fTemp52))));
			double fTemp452 = (fConst54 * fRec971[1]);
			double fTemp453 = (fConst55 * fRec974[1]);
			fRec976[0] = (fTemp451 + (fTemp452 + (fRec976[1] + fTemp453)));
			fRec974[0] = fRec976[0];
			double fRec975 = ((fTemp453 + fTemp452) + fTemp451);
			fRec973[0] = (fRec974[0] + fRec973[1]);
			fRec971[0] = fRec973[0];
			double fRec972 = fRec975;
			fRec970[0] = (fTemp450 + (fRec972 + fRec970[1]));
			fRec968[0] = fRec970[0];
			double fRec969 = (fRec972 + fTemp450);
			double fTemp454 = (fConst39 * ((36385884360000.0 * fTemp21) - ((6693323324000.0 * fTemp23) + (23429614470000.0 * fTemp22))));
			double fTemp455 = (fConst40 * fRec977[1]);
			fRec979[0] = (fTemp454 + (fRec979[1] + fTemp455));
			fRec977[0] = fRec979[0];
			double fRec978 = (fTemp455 + fTemp454);
			fVec20[(IOTA & 1023)] = ((16441234040000.0 * fTemp58) + (fRec936 + (fRec951 + (fRec963 + (fRec969 + fRec978)))));
			output20[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec20[((IOTA - iConst63) & 1023)])));
			double fTemp456 = ((fConst48 * fRec989[1]) + (fConst47 * (((27978375640000.0 * fTemp10) + (((17954500210000.0 * fTemp12) + (47550438760000.0 * fTemp15)) + (13064854610000.0 * fTemp17))) - ((21720044120000.0 * fTemp14) + ((18772405940000.0 * fTemp13) + ((66100408700000.0 * fTemp16) + (10678070550000.0 * fTemp11)))))));
			double fTemp457 = (fConst49 * fRec992[1]);
			fRec994[0] = ((fTemp456 + fRec994[1]) + fTemp457);
			fRec992[0] = fRec994[0];
			double fRec993 = (fTemp456 + fTemp457);
			fRec991[0] = (fRec992[0] + fRec991[1]);
			fRec989[0] = fRec991[0];
			double fRec990 = fRec993;
			double fTemp458 = (fConst45 * fRec986[1]);
			double fTemp459 = (fConst44 * fRec983[1]);
			fRec988[0] = (((fRec990 + fRec988[1]) + fTemp458) + fTemp459);
			fRec986[0] = fRec988[0];
			double fRec987 = ((fRec990 + fTemp458) + fTemp459);
			fRec985[0] = (fRec986[0] + fRec985[1]);
			fRec983[0] = fRec985[0];
			double fRec984 = fRec987;
			double fTemp460 = (fConst42 * fRec980[1]);
			fRec982[0] = ((fRec984 + fRec982[1]) + fTemp460);
			fRec980[0] = fRec982[0];
			double fRec981 = (fRec984 + fTemp460);
			double fTemp461 = (fConst57 * fRec995[1]);
			double fTemp462 = (fConst58 * fRec998[1]);
			double fTemp463 = (fConst60 * (((59663813710000.0 * fTemp32) + ((44246840730000.0 * fTemp28) + (33765724800000.0 * fTemp29))) - ((3968851865000.0 * fTemp27) + ((23790322120000.0 * fTemp33) + ((1031717251000.0 * fTemp31) + ((20057817120000.0 * fTemp26) + (23561363590000.0 * fTemp30)))))));
			double fTemp464 = (fConst61 * fRec1001[1]);
			double fTemp465 = (fConst62 * fRec1004[1]);
			fRec1006[0] = (fTemp463 + (fTemp464 + (fRec1006[1] + fTemp465)));
			fRec1004[0] = fRec1006[0];
			double fRec1005 = ((fTemp465 + fTemp464) + fTemp463);
			fRec1003[0] = (fRec1004[0] + fRec1003[1]);
			fRec1001[0] = fRec1003[0];
			double fRec1002 = fRec1005;
			fRec1000[0] = (fTemp461 + (fTemp462 + (fRec1002 + fRec1000[1])));
			fRec998[0] = fRec1000[0];
			double fRec999 = (fTemp461 + (fRec1002 + fTemp462));
			fRec997[0] = (fRec998[0] + fRec997[1]);
			fRec995[0] = fRec997[0];
			double fRec996 = fRec999;
			double fTemp466 = (fConst51 * fRec1007[1]);
			double fTemp467 = (fConst53 * ((((27209244740000.0 * fTemp48) + (2764606395000.0 * fTemp53)) + (44655996180000.0 * fTemp51)) - ((((37055047310000.0 * fTemp49) + (37056907660000.0 * fTemp54)) + (23636911100000.0 * fTemp50)) + (9376118550000.0 * fTemp52))));
			double fTemp468 = (fConst54 * fRec1010[1]);
			double fTemp469 = (fConst55 * fRec1013[1]);
			fRec1015[0] = (fTemp467 + (fTemp468 + (fRec1015[1] + fTemp469)));
			fRec1013[0] = fRec1015[0];
			double fRec1014 = ((fTemp469 + fTemp468) + fTemp467);
			fRec1012[0] = (fRec1013[0] + fRec1012[1]);
			fRec1010[0] = fRec1012[0];
			double fRec1011 = fRec1014;
			fRec1009[0] = (fTemp466 + (fRec1011 + fRec1009[1]));
			fRec1007[0] = fRec1009[0];
			double fRec1008 = (fRec1011 + fTemp466);
			double fTemp470 = (fConst39 * (((7455567180000.0 * fTemp23) + (29705124320000.0 * fTemp21)) - (22217792500000.0 * fTemp22)));
			double fTemp471 = (fConst40 * fRec1016[1]);
			fRec1018[0] = (fTemp470 + (fRec1018[1] + fTemp471));
			fRec1016[0] = fRec1018[0];
			double fRec1017 = (fTemp471 + fTemp470);
			double fTemp472 = (fConst35 * (((12924707210000.0 * fTemp39) + (19175279630000.0 * fTemp40)) - (((15954647460000.0 * fTemp42) + (1372211308000.0 * fTemp41)) + (46526935400000.0 * fTemp43))));
			double fTemp473 = (fConst36 * fRec1019[1]);
			double fTemp474 = (fConst37 * fRec1022[1]);
			fRec1024[0] = (fTemp472 + (fTemp473 + (fRec1024[1] + fTemp474)));
			fRec1022[0] = fRec1024[0];
			double fRec1023 = ((fTemp474 + fTemp473) + fTemp472);
			fRec1021[0] = (fRec1022[0] + fRec1021[1]);
			fRec1019[0] = fRec1021[0];
			double fRec1020 = fRec1023;
			fVec21[(IOTA & 1023)] = ((fRec981 + (fRec996 + (fRec1008 + (fRec1017 + fRec1020)))) + (17096248230000.0 * fTemp58));
			output21[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec21[((IOTA - iConst63) & 1023)])));
			double fTemp475 = (fConst42 * fRec1025[1]);
			double fTemp476 = (fConst44 * fRec1028[1]);
			double fTemp477 = (fConst45 * fRec1031[1]);
			double fTemp478 = (fConst47 * (((32589225550000.0 * fTemp10) + ((43481924670000.0 * fTemp14) + ((56737759770000.0 * fTemp16) + (15032374330000.0 * fTemp13)))) - ((7517257108000.0 * fTemp17) + ((11568930220000.0 * fTemp15) + ((22654453500000.0 * fTemp12) + (35923317230000.0 * fTemp11))))));
			double fTemp479 = (fConst48 * fRec1034[1]);
			double fTemp480 = (fConst49 * fRec1037[1]);
			fRec1039[0] = (fTemp478 + (fTemp479 + (fRec1039[1] + fTemp480)));
			fRec1037[0] = fRec1039[0];
			double fRec1038 = ((fTemp480 + fTemp479) + fTemp478);
			fRec1036[0] = (fRec1037[0] + fRec1036[1]);
			fRec1034[0] = fRec1036[0];
			double fRec1035 = fRec1038;
			fRec1033[0] = (fTemp476 + (fTemp477 + (fRec1035 + fRec1033[1])));
			fRec1031[0] = fRec1033[0];
			double fRec1032 = (fTemp476 + (fRec1035 + fTemp477));
			fRec1030[0] = (fRec1031[0] + fRec1030[1]);
			fRec1028[0] = fRec1030[0];
			double fRec1029 = fRec1032;
			fRec1027[0] = (fTemp475 + (fRec1029 + fRec1027[1]));
			fRec1025[0] = fRec1027[0];
			double fRec1026 = (fRec1029 + fTemp475);
			double fTemp481 = (fConst39 * (((20699773720000.0 * fTemp23) + (35157021770000.0 * fTemp21)) - (9753724449000.0 * fTemp22)));
			double fTemp482 = (fConst40 * fRec1040[1]);
			fRec1042[0] = (fTemp481 + (fRec1042[1] + fTemp482));
			fRec1040[0] = fRec1042[0];
			double fRec1041 = (fTemp482 + fTemp481);
			double fTemp483 = (fConst57 * fRec1043[1]);
			double fTemp484 = (fConst58 * fRec1046[1]);
			double fTemp485 = (fConst60 * (((3077337226000.0 * fTemp27) + ((27695193070000.0 * fTemp28) + (57193693770000.0 * fTemp30))) - ((27541719710000.0 * fTemp33) + ((8795716845000.0 * fTemp32) + (((47067495720000.0 * fTemp26) + (28002292820000.0 * fTemp29)) + (4663010174000.0 * fTemp31))))));
			double fTemp486 = (fConst61 * fRec1049[1]);
			double fTemp487 = (fConst62 * fRec1052[1]);
			fRec1054[0] = (fTemp485 + (fTemp486 + (fRec1054[1] + fTemp487)));
			fRec1052[0] = fRec1054[0];
			double fRec1053 = ((fTemp487 + fTemp486) + fTemp485);
			fRec1051[0] = (fRec1052[0] + fRec1051[1]);
			fRec1049[0] = fRec1051[0];
			double fRec1050 = fRec1053;
			fRec1048[0] = (fTemp483 + (fTemp484 + (fRec1050 + fRec1048[1])));
			fRec1046[0] = fRec1048[0];
			double fRec1047 = (fTemp483 + (fRec1050 + fTemp484));
			fRec1045[0] = (fRec1046[0] + fRec1045[1]);
			fRec1043[0] = fRec1045[0];
			double fRec1044 = fRec1047;
			double fTemp488 = (fConst35 * ((47071764210000.0 * fTemp39) - ((((18393942690000.0 * fTemp42) + (2139830106000.0 * fTemp41)) + (20461826730000.0 * fTemp43)) + (14953782570000.0 * fTemp40))));
			double fTemp489 = (fConst36 * fRec1055[1]);
			double fTemp490 = (fConst37 * fRec1058[1]);
			fRec1060[0] = (fTemp488 + (fTemp489 + (fRec1060[1] + fTemp490)));
			fRec1058[0] = fRec1060[0];
			double fRec1059 = ((fTemp490 + fTemp489) + fTemp488);
			fRec1057[0] = (fRec1058[0] + fRec1057[1]);
			fRec1055[0] = fRec1057[0];
			double fRec1056 = fRec1059;
			double fTemp491 = (fConst51 * fRec1061[1]);
			double fTemp492 = (fConst53 * (((24382024550000.0 * fTemp53) + (27801498150000.0 * fTemp52)) - (((((1114643156000.0 * fTemp48) + (42900962970000.0 * fTemp49)) + (42028451010000.0 * fTemp54)) + (7382618410000.0 * fTemp50)) + (36260715720000.0 * fTemp51))));
			double fTemp493 = (fConst54 * fRec1064[1]);
			double fTemp494 = (fConst55 * fRec1067[1]);
			fRec1069[0] = (fTemp492 + (fTemp493 + (fRec1069[1] + fTemp494)));
			fRec1067[0] = fRec1069[0];
			double fRec1068 = ((fTemp494 + fTemp493) + fTemp492);
			fRec1066[0] = (fRec1067[0] + fRec1066[1]);
			fRec1064[0] = fRec1066[0];
			double fRec1065 = fRec1068;
			fRec1063[0] = (fTemp491 + (fRec1065 + fRec1063[1]));
			fRec1061[0] = fRec1063[0];
			double fRec1062 = (fRec1065 + fTemp491);
			fVec22[(IOTA & 1023)] = ((15967958640000.0 * fTemp58) + (fRec1026 + (fRec1041 + (fRec1044 + (fRec1056 + fRec1062)))));
			output22[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec22[((IOTA - iConst63) & 1023)])));
			double fTemp495 = (fConst51 * fRec1070[1]);
			double fTemp496 = (fConst53 * ((((40109243780000.0 * fTemp49) + (26874285640000.0 * fTemp53)) + (5733402714000.0 * fTemp50)) - ((26545667060000.0 * fTemp52) + (((8020355369000.0 * fTemp48) + (44543540110000.0 * fTemp54)) + (43781968870000.0 * fTemp51)))));
			double fTemp497 = (fConst54 * fRec1073[1]);
			double fTemp498 = (fConst55 * fRec1076[1]);
			fRec1078[0] = (fTemp496 + (fTemp497 + (fRec1078[1] + fTemp498)));
			fRec1076[0] = fRec1078[0];
			double fRec1077 = ((fTemp498 + fTemp497) + fTemp496);
			fRec1075[0] = (fRec1076[0] + fRec1075[1]);
			fRec1073[0] = fRec1075[0];
			double fRec1074 = fRec1077;
			fRec1072[0] = (fTemp495 + (fRec1074 + fRec1072[1]));
			fRec1070[0] = fRec1072[0];
			double fRec1071 = (fRec1074 + fTemp495);
			double fTemp499 = (fConst39 * (((22548972970000.0 * fTemp23) + (37044659040000.0 * fTemp21)) + (7785720500000.0 * fTemp22)));
			double fTemp500 = (fConst40 * fRec1079[1]);
			fRec1081[0] = (fTemp499 + (fRec1081[1] + fTemp500));
			fRec1079[0] = fRec1081[0];
			double fRec1080 = (fTemp500 + fTemp499);
			double fTemp501 = (fConst42 * fRec1082[1]);
			double fTemp502 = (fConst44 * fRec1085[1]);
			double fTemp503 = (fConst45 * fRec1088[1]);
			double fTemp504 = (fConst47 * (((18778481600000.0 * fTemp13) + (17398217030000.0 * fTemp17)) - ((31026408960000.0 * fTemp10) + ((41197512310000.0 * fTemp14) + ((15427271660000.0 * fTemp15) + ((53039161830000.0 * fTemp16) + ((12479300570000.0 * fTemp12) + (14901615040000.0 * fTemp11))))))));
			double fTemp505 = (fConst48 * fRec1091[1]);
			double fTemp506 = (fConst49 * fRec1094[1]);
			fRec1096[0] = (fTemp504 + (fTemp505 + (fRec1096[1] + fTemp506)));
			fRec1094[0] = fRec1096[0];
			double fRec1095 = ((fTemp506 + fTemp505) + fTemp504);
			fRec1093[0] = (fRec1094[0] + fRec1093[1]);
			fRec1091[0] = fRec1093[0];
			double fRec1092 = fRec1095;
			fRec1090[0] = (fTemp502 + (fTemp503 + (fRec1092 + fRec1090[1])));
			fRec1088[0] = fRec1090[0];
			double fRec1089 = (fTemp502 + (fRec1092 + fTemp503));
			fRec1087[0] = (fRec1088[0] + fRec1087[1]);
			fRec1085[0] = fRec1087[0];
			double fRec1086 = fRec1089;
			fRec1084[0] = (fTemp501 + (fRec1086 + fRec1084[1]));
			fRec1082[0] = fRec1084[0];
			double fRec1083 = (fRec1086 + fTemp501);
			double fTemp507 = (fConst35 * ((((16520297580000.0 * fTemp42) + (51725692440000.0 * fTemp39)) + (16550719090000.0 * fTemp43)) - ((1465007414000.0 * fTemp41) + (19892206050000.0 * fTemp40))));
			double fTemp508 = (fConst36 * fRec1097[1]);
			double fTemp509 = (fConst37 * fRec1100[1]);
			fRec1102[0] = (fTemp507 + (fTemp508 + (fRec1102[1] + fTemp509)));
			fRec1100[0] = fRec1102[0];
			double fRec1101 = ((fTemp509 + fTemp508) + fTemp507);
			fRec1099[0] = (fRec1100[0] + fRec1099[1]);
			fRec1097[0] = fRec1099[0];
			double fRec1098 = fRec1101;
			double fTemp510 = (fConst57 * fRec1103[1]);
			double fTemp511 = (fConst58 * fRec1106[1]);
			double fTemp512 = (fConst60 * (((26124154910000.0 * fTemp33) + (816847158300.0 * fTemp31)) - ((7908120258000.0 * fTemp27) + ((17309901170000.0 * fTemp32) + ((54287360920000.0 * fTemp30) + (((51895814490000.0 * fTemp26) + (23258213040000.0 * fTemp28)) + (32069434730000.0 * fTemp29)))))));
			double fTemp513 = (fConst61 * fRec1109[1]);
			double fTemp514 = (fConst62 * fRec1112[1]);
			fRec1114[0] = (fTemp512 + (fTemp513 + (fRec1114[1] + fTemp514)));
			fRec1112[0] = fRec1114[0];
			double fRec1113 = ((fTemp514 + fTemp513) + fTemp512);
			fRec1111[0] = (fRec1112[0] + fRec1111[1]);
			fRec1109[0] = fRec1111[0];
			double fRec1110 = fRec1113;
			fRec1108[0] = (fTemp510 + (fTemp511 + (fRec1110 + fRec1108[1])));
			fRec1106[0] = fRec1108[0];
			double fRec1107 = (fTemp510 + (fRec1110 + fTemp511));
			fRec1105[0] = (fRec1106[0] + fRec1105[1]);
			fRec1103[0] = fRec1105[0];
			double fRec1104 = fRec1107;
			fVec23[(IOTA & 1023)] = ((16202936820000.0 * fTemp58) + (fRec1071 + (fRec1080 + (fRec1083 + (fRec1098 + fRec1104)))));
			output23[i] = FAUSTFLOAT((0.71526648599819331 * (fRec0[0] * fVec23[((IOTA - iConst63) & 1023)])));
			double fTemp515 = (fConst65 * fRec1115[1]);
			double fTemp516 = (fConst66 * fRec1118[1]);
			double fTemp517 = (fConst68 * (((584692556900.0 * fTemp27) + ((29128839730000.0 * fTemp33) + ((1340518632000.0 * fTemp32) + ((59626311540000.0 * fTemp26) + (60268709910000.0 * fTemp28))))) - ((6331705681000.0 * fTemp31) + ((318529525600.0 * fTemp29) + (1175135557000.0 * fTemp30)))));
			double fTemp518 = (fConst69 * fRec1121[1]);
			double fTemp519 = (fConst70 * fRec1124[1]);
			fRec1126[0] = (fTemp517 + (fTemp518 + (fRec1126[1] + fTemp519)));
			fRec1124[0] = fRec1126[0];
			double fRec1125 = ((fTemp519 + fTemp518) + fTemp517);
			fRec1123[0] = (fRec1124[0] + fRec1123[1]);
			fRec1121[0] = fRec1123[0];
			double fRec1122 = fRec1125;
			fRec1120[0] = (fTemp515 + (fTemp516 + (fRec1122 + fRec1120[1])));
			fRec1118[0] = fRec1120[0];
			double fRec1119 = (fTemp515 + (fRec1122 + fTemp516));
			fRec1117[0] = (fRec1118[0] + fRec1117[1]);
			fRec1115[0] = fRec1117[0];
			double fRec1116 = fRec1119;
			double fTemp520 = (fConst72 * fRec1127[1]);
			double fTemp521 = (fConst74 * fRec1130[1]);
			double fTemp522 = (fConst75 * fRec1133[1]);
			double fTemp523 = (fConst77 * (((70385191110000.0 * fTemp10) + ((146001627100.0 * fTemp13) + ((6568832668000.0 * fTemp15) + (11644407150000.0 * fTemp11)))) - ((((220605262800.0 * fTemp12) + (1078377583000.0 * fTemp16)) + (6217903355000.0 * fTemp14)) + (739688633100.0 * fTemp17))));
			double fTemp524 = (fConst78 * fRec1136[1]);
			double fTemp525 = (fConst79 * fRec1139[1]);
			fRec1141[0] = (fTemp523 + (fTemp524 + (fRec1141[1] + fTemp525)));
			fRec1139[0] = fRec1141[0];
			double fRec1140 = ((fTemp525 + fTemp524) + fTemp523);
			fRec1138[0] = (fRec1139[0] + fRec1138[1]);
			fRec1136[0] = fRec1138[0];
			double fRec1137 = fRec1140;
			fRec1135[0] = (fTemp521 + (fTemp522 + (fRec1137 + fRec1135[1])));
			fRec1133[0] = fRec1135[0];
			double fRec1134 = (fTemp521 + (fRec1137 + fTemp522));
			fRec1132[0] = (fRec1133[0] + fRec1132[1]);
			fRec1130[0] = fRec1132[0];
			double fRec1131 = fRec1134;
			fRec1129[0] = (fTemp520 + (fRec1131 + fRec1129[1]));
			fRec1127[0] = fRec1129[0];
			double fRec1128 = (fRec1131 + fTemp520);
			double fTemp526 = (fConst81 * fRec1142[1]);
			double fTemp527 = (fConst83 * ((((((1299516083000.0 * fTemp48) + (22205119040000.0 * fTemp49)) + (39806154010000.0 * fTemp53)) + (19024679200000.0 * fTemp54)) + (39372435730000.0 * fTemp50)) - ((376411345900.0 * fTemp51) + (1461605159000.0 * fTemp52))));
			double fTemp528 = (fConst84 * fRec1145[1]);
			double fTemp529 = (fConst85 * fRec1148[1]);
			fRec1150[0] = (fTemp527 + (fTemp528 + (fRec1150[1] + fTemp529)));
			fRec1148[0] = fRec1150[0];
			double fRec1149 = ((fTemp529 + fTemp528) + fTemp527);
			fRec1147[0] = (fRec1148[0] + fRec1147[1]);
			fRec1145[0] = fRec1147[0];
			double fRec1146 = fRec1149;
			fRec1144[0] = (fTemp526 + (fRec1146 + fRec1144[1]));
			fRec1142[0] = fRec1144[0];
			double fRec1143 = (fRec1146 + fTemp526);
			double fTemp530 = (fConst87 * (((27613886750000.0 * fTemp23) + (11363778980000.0 * fTemp21)) + (27823156700000.0 * fTemp22)));
			double fTemp531 = (fConst88 * fRec1151[1]);
			fRec1153[0] = (fTemp530 + (fRec1153[1] + fTemp531));
			fRec1151[0] = fRec1153[0];
			double fRec1152 = (fTemp531 + fTemp530);
			double fTemp532 = (fConst90 * ((((27086515450000.0 * fTemp42) + ((31655468230000.0 * fTemp39) + (66253348390000.0 * fTemp41))) + (31229906700000.0 * fTemp43)) - (125856134100.0 * fTemp40)));
			double fTemp533 = (fConst91 * fRec1154[1]);
			double fTemp534 = (fConst92 * fRec1157[1]);
			fRec1159[0] = (fTemp532 + (fTemp533 + (fRec1159[1] + fTemp534)));
			fRec1157[0] = fRec1159[0];
			double fRec1158 = ((fTemp534 + fTemp533) + fTemp532);
			fRec1156[0] = (fRec1157[0] + fRec1156[1]);
			fRec1154[0] = fRec1156[0];
			double fRec1155 = fRec1158;
			fVec24[(IOTA & 127)] = ((42941845320000.0 * fTemp58) + (fRec1116 + (fRec1128 + (fRec1143 + (fRec1152 + fRec1155)))));
			output24[i] = FAUSTFLOAT((0.96133694670280023 * (fRec0[0] * fVec24[((IOTA - iConst93) & 127)])));
			double fTemp535 = (fConst72 * fRec1160[1]);
			double fTemp536 = (fConst74 * fRec1163[1]);
			double fTemp537 = (fConst75 * fRec1166[1]);
			double fTemp538 = (fConst77 * (((14698614350000.0 * fTemp11) + (768987500700.0 * fTemp17)) - ((68336674070000.0 * fTemp10) + (((((75327092760.0 * fTemp12) + (1539201446000.0 * fTemp16)) + (8987677178000.0 * fTemp15)) + (49495047240.0 * fTemp13)) + (5621139675000.0 * fTemp14)))));
			double fTemp539 = (fConst78 * fRec1169[1]);
			double fTemp540 = (fConst79 * fRec1172[1]);
			fRec1174[0] = (fTemp538 + (fTemp539 + (fRec1174[1] + fTemp540)));
			fRec1172[0] = fRec1174[0];
			double fRec1173 = ((fTemp540 + fTemp539) + fTemp538);
			fRec1171[0] = (fRec1172[0] + fRec1171[1]);
			fRec1169[0] = fRec1171[0];
			double fRec1170 = fRec1173;
			fRec1168[0] = (fTemp536 + (fTemp537 + (fRec1170 + fRec1168[1])));
			fRec1166[0] = fRec1168[0];
			double fRec1167 = (fTemp536 + (fRec1170 + fTemp537));
			fRec1165[0] = (fRec1166[0] + fRec1165[1]);
			fRec1163[0] = fRec1165[0];
			double fRec1164 = fRec1167;
			fRec1162[0] = (fTemp535 + (fRec1164 + fRec1162[1]));
			fRec1160[0] = fRec1162[0];
			double fRec1161 = (fRec1164 + fTemp535);
			double fTemp541 = (fConst81 * fRec1175[1]);
			double fTemp542 = (fConst83 * (((18224582750.0 * fTemp51) + ((18928586420000.0 * fTemp54) + (39538725720000.0 * fTemp50))) - ((((1806040884000.0 * fTemp48) + (23828798560000.0 * fTemp49)) + (38174618870000.0 * fTemp53)) + (848701037400.0 * fTemp52))));
			double fTemp543 = (fConst84 * fRec1178[1]);
			double fTemp544 = (fConst85 * fRec1181[1]);
			fRec1183[0] = (fTemp542 + (fTemp543 + (fRec1183[1] + fTemp544)));
			fRec1181[0] = fRec1183[0];
			double fRec1182 = ((fTemp544 + fTemp543) + fTemp542);
			fRec1180[0] = (fRec1181[0] + fRec1180[1]);
			fRec1178[0] = fRec1180[0];
			double fRec1179 = fRec1182;
			fRec1177[0] = (fTemp541 + (fRec1179 + fRec1177[1]));
			fRec1175[0] = fRec1177[0];
			double fRec1176 = (fRec1179 + fTemp541);
			double fTemp545 = (fConst90 * ((((66266331110000.0 * fTemp41) + (31412557160000.0 * fTemp43)) + (130161921300.0 * fTemp40)) - ((26329777440000.0 * fTemp42) + (29842330130000.0 * fTemp39))));
			double fTemp546 = (fConst91 * fRec1184[1]);
			double fTemp547 = (fConst92 * fRec1187[1]);
			fRec1189[0] = (fTemp545 + (fTemp546 + (fRec1189[1] + fTemp547)));
			fRec1187[0] = fRec1189[0];
			double fRec1188 = ((fTemp547 + fTemp546) + fTemp545);
			fRec1186[0] = (fRec1187[0] + fRec1186[1]);
			fRec1184[0] = fRec1186[0];
			double fRec1185 = fRec1188;
			double fTemp548 = (fConst65 * fRec1190[1]);
			double fTemp549 = (fConst66 * fRec1193[1]);
			double fTemp550 = (fConst68 * (((618345589200.0 * fTemp27) + (60184175320000.0 * fTemp28)) - ((31105039190000.0 * fTemp33) + ((3571702765000.0 * fTemp32) + ((6622226448000.0 * fTemp31) + ((211725885500.0 * fTemp30) + ((61421826290000.0 * fTemp26) + (102191804000.0 * fTemp29))))))));
			double fTemp551 = (fConst69 * fRec1196[1]);
			double fTemp552 = (fConst70 * fRec1199[1]);
			fRec1201[0] = (fTemp550 + (fTemp551 + (fRec1201[1] + fTemp552)));
			fRec1199[0] = fRec1201[0];
			double fRec1200 = ((fTemp552 + fTemp551) + fTemp550);
			fRec1198[0] = (fRec1199[0] + fRec1198[1]);
			fRec1196[0] = fRec1198[0];
			double fRec1197 = fRec1200;
			fRec1195[0] = (fTemp548 + (fTemp549 + (fRec1197 + fRec1195[1])));
			fRec1193[0] = fRec1195[0];
			double fRec1194 = (fTemp548 + (fRec1197 + fTemp549));
			fRec1192[0] = (fRec1193[0] + fRec1192[1]);
			fRec1190[0] = fRec1192[0];
			double fRec1191 = fRec1194;
			double fTemp553 = (fConst87 * (((11466288420000.0 * fTemp21) + (27855240680000.0 * fTemp22)) - (27744775620000.0 * fTemp23)));
			double fTemp554 = (fConst88 * fRec1202[1]);
			fRec1204[0] = (fTemp553 + (fRec1204[1] + fTemp554));
			fRec1202[0] = fRec1204[0];
			double fRec1203 = (fTemp554 + fTemp553);
			fVec25[(IOTA & 127)] = ((42974623510000.0 * fTemp58) + (fRec1161 + (fRec1176 + (fRec1185 + (fRec1191 + fRec1203)))));
			output25[i] = FAUSTFLOAT((0.96133694670280023 * (fRec0[0] * fVec25[((IOTA - iConst93) & 127)])));
			double fTemp555 = (fConst72 * fRec1205[1]);
			double fTemp556 = (fConst74 * fRec1208[1]);
			double fTemp557 = (fConst75 * fRec1211[1]);
			double fTemp558 = (fConst77 * (((70258823770000.0 * fTemp10) + ((255280130900.0 * fTemp17) + ((9344168214000.0 * fTemp14) + ((136359505600.0 * fTemp13) + ((515187204600.0 * fTemp12) + (10977314200000.0 * fTemp11)))))) - ((1036774509000.0 * fTemp16) + (8957785155000.0 * fTemp15))));
			double fTemp559 = (fConst78 * fRec1214[1]);
			double fTemp560 = (fConst79 * fRec1217[1]);
			fRec1219[0] = (fTemp558 + (fTemp559 + (fRec1219[1] + fTemp560)));
			fRec1217[0] = fRec1219[0];
			double fRec1218 = ((fTemp560 + fTemp559) + fTemp558);
			fRec1216[0] = (fRec1217[0] + fRec1216[1]);
			fRec1214[0] = fRec1216[0];
			double fRec1215 = fRec1218;
			fRec1213[0] = (fTemp556 + (fTemp557 + (fRec1215 + fRec1213[1])));
			fRec1211[0] = fRec1213[0];
			double fRec1212 = (fTemp556 + (fRec1215 + fTemp557));
			fRec1210[0] = (fRec1211[0] + fRec1210[1]);
			fRec1208[0] = fRec1210[0];
			double fRec1209 = fRec1212;
			fRec1207[0] = (fTemp555 + (fRec1209 + fRec1207[1]));
			fRec1205[0] = fRec1207[0];
			double fRec1206 = (fRec1209 + fTemp555);
			double fTemp561 = (fConst65 * fRec1220[1]);
			double fTemp562 = (fConst66 * fRec1223[1]);
			double fTemp563 = (fConst68 * (((608315895200.0 * fTemp27) + ((29267673550000.0 * fTemp33) + (3799259335000.0 * fTemp30))) - ((3581371804000.0 * fTemp32) + ((((61141462860000.0 * fTemp26) + (60613985440000.0 * fTemp28)) + (250266416500.0 * fTemp29)) + (6022225182000.0 * fTemp31)))));
			double fTemp564 = (fConst69 * fRec1226[1]);
			double fTemp565 = (fConst70 * fRec1229[1]);
			fRec1231[0] = (fTemp563 + (fTemp564 + (fRec1231[1] + fTemp565)));
			fRec1229[0] = fRec1231[0];
			double fRec1230 = ((fTemp565 + fTemp564) + fTemp563);
			fRec1228[0] = (fRec1229[0] + fRec1228[1]);
			fRec1226[0] = fRec1228[0];
			double fRec1227 = fRec1230;
			fRec1225[0] = (fTemp561 + (fTemp562 + (fRec1227 + fRec1225[1])));
			fRec1223[0] = fRec1225[0];
			double fRec1224 = (fTemp561 + (fRec1227 + fTemp562));
			fRec1222[0] = (fRec1223[0] + fRec1222[1]);
			fRec1220[0] = fRec1222[0];
			double fRec1221 = fRec1224;
			double fTemp566 = (fConst81 * fRec1232[1]);
			double fTemp567 = (fConst83 * ((((22355197200000.0 * fTemp49) + (19223407390000.0 * fTemp54)) + (1710602896000.0 * fTemp52)) - ((((1836577913000.0 * fTemp48) + (38376245350000.0 * fTemp53)) + (38651982390000.0 * fTemp50)) + (326974530100.0 * fTemp51))));
			double fTemp568 = (fConst84 * fRec1235[1]);
			double fTemp569 = (fConst85 * fRec1238[1]);
			fRec1240[0] = (fTemp567 + (fTemp568 + (fRec1240[1] + fTemp569)));
			fRec1238[0] = fRec1240[0];
			double fRec1239 = ((fTemp569 + fTemp568) + fTemp567);
			fRec1237[0] = (fRec1238[0] + fRec1237[1]);
			fRec1235[0] = fRec1237[0];
			double fRec1236 = fRec1239;
			fRec1234[0] = (fTemp566 + (fRec1236 + fRec1234[1]));
			fRec1232[0] = fRec1234[0];
			double fRec1233 = (fRec1236 + fTemp566);
			double fTemp570 = (fConst87 * ((11241417690000.0 * fTemp21) - ((27773797360000.0 * fTemp23) + (27653781550000.0 * fTemp22))));
			double fTemp571 = (fConst88 * fRec1241[1]);
			fRec1243[0] = (fTemp570 + (fRec1243[1] + fTemp571));
			fRec1241[0] = fRec1243[0];
			double fRec1242 = (fTemp571 + fTemp570);
			double fTemp572 = (fConst90 * (((27094799910000.0 * fTemp42) + (66228882630000.0 * fTemp41)) - (((30111744930000.0 * fTemp39) + (30426391200000.0 * fTemp43)) + (137205210600.0 * fTemp40))));
			double fTemp573 = (fConst91 * fRec1244[1]);
			double fTemp574 = (fConst92 * fRec1247[1]);
			fRec1249[0] = (fTemp572 + (fTemp573 + (fRec1249[1] + fTemp574)));
			fRec1247[0] = fRec1249[0];
			double fRec1248 = ((fTemp574 + fTemp573) + fTemp572);
			fRec1246[0] = (fRec1247[0] + fRec1246[1]);
			fRec1244[0] = fRec1246[0];
			double fRec1245 = fRec1248;
			fVec26[(IOTA & 127)] = ((42903024400000.0 * fTemp58) + (fRec1206 + (fRec1221 + (fRec1233 + (fRec1242 + fRec1245)))));
			output26[i] = FAUSTFLOAT((0.96133694670280023 * (fRec0[0] * fVec26[((IOTA - iConst93) & 127)])));
			double fTemp575 = (fConst72 * fRec1250[1]);
			double fTemp576 = (fConst74 * fRec1253[1]);
			double fTemp577 = (fConst75 * fRec1256[1]);
			double fTemp578 = (fConst77 * (((9137326003000.0 * fTemp14) + ((291865311000.0 * fTemp13) + ((5398118086000.0 * fTemp15) + ((793518961800.0 * fTemp12) + (16175420020000.0 * fTemp11))))) - ((68435559960000.0 * fTemp10) + ((1200742180000.0 * fTemp16) + (325852615800.0 * fTemp17)))));
			double fTemp579 = (fConst78 * fRec1259[1]);
			double fTemp580 = (fConst79 * fRec1262[1]);
			fRec1264[0] = (fTemp578 + (fTemp579 + (fRec1264[1] + fTemp580)));
			fRec1262[0] = fRec1264[0];
			double fRec1263 = ((fTemp580 + fTemp579) + fTemp578);
			fRec1261[0] = (fRec1262[0] + fRec1261[1]);
			fRec1259[0] = fRec1261[0];
			double fRec1260 = fRec1263;
			fRec1258[0] = (fTemp576 + (fTemp577 + (fRec1260 + fRec1258[1])));
			fRec1256[0] = fRec1258[0];
			double fRec1257 = (fTemp576 + (fRec1260 + fTemp577));
			fRec1255[0] = (fRec1256[0] + fRec1255[1]);
			fRec1253[0] = fRec1255[0];
			double fRec1254 = fRec1257;
			fRec1252[0] = (fTemp575 + (fRec1254 + fRec1252[1]));
			fRec1250[0] = fRec1252[0];
			double fRec1251 = (fRec1254 + fTemp575);
			double fTemp581 = (fConst81 * fRec1265[1]);
			double fTemp582 = (fConst83 * (((((994468254400.0 * fTemp48) + (39896258230000.0 * fTemp53)) + (18909095780000.0 * fTemp54)) + (1671457174000.0 * fTemp52)) - (((23660716680000.0 * fTemp49) + (38318712650000.0 * fTemp50)) + (806072694400.0 * fTemp51))));
			double fTemp583 = (fConst84 * fRec1268[1]);
			double fTemp584 = (fConst85 * fRec1271[1]);
			fRec1273[0] = (fTemp582 + (fTemp583 + (fRec1273[1] + fTemp584)));
			fRec1271[0] = fRec1273[0];
			double fRec1272 = ((fTemp584 + fTemp583) + fTemp582);
			fRec1270[0] = (fRec1271[0] + fRec1270[1]);
			fRec1268[0] = fRec1270[0];
			double fRec1269 = fRec1272;
			fRec1267[0] = (fTemp581 + (fRec1269 + fRec1267[1]));
			fRec1265[0] = fRec1267[0];
			double fRec1266 = (fRec1269 + fTemp581);
			double fTemp585 = (fConst90 * (((31780511890000.0 * fTemp39) + (66287251060000.0 * fTemp41)) - (((26355094750000.0 * fTemp42) + (30059096580000.0 * fTemp43)) + (208712693900.0 * fTemp40))));
			double fTemp586 = (fConst91 * fRec1274[1]);
			double fTemp587 = (fConst92 * fRec1277[1]);
			fRec1279[0] = (fTemp585 + (fTemp586 + (fRec1279[1] + fTemp587)));
			fRec1277[0] = fRec1279[0];
			double fRec1278 = ((fTemp587 + fTemp586) + fTemp585);
			fRec1276[0] = (fRec1277[0] + fRec1276[1]);
			fRec1274[0] = fRec1276[0];
			double fRec1275 = fRec1278;
			double fTemp588 = (fConst65 * fRec1280[1]);
			double fTemp589 = (fConst66 * fRec1283[1]);
			double fTemp590 = (fConst68 * (((642804879800.0 * fTemp27) + ((180904355300.0 * fTemp32) + ((59644854740000.0 * fTemp26) + (3594761192000.0 * fTemp30)))) - ((30906339500000.0 * fTemp33) + (((61014773380000.0 * fTemp28) + (739761559000.0 * fTemp29)) + (7209120649000.0 * fTemp31)))));
			double fTemp591 = (fConst69 * fRec1286[1]);
			double fTemp592 = (fConst70 * fRec1289[1]);
			fRec1291[0] = (fTemp590 + (fTemp591 + (fRec1291[1] + fTemp592)));
			fRec1289[0] = fRec1291[0];
			double fRec1290 = ((fTemp592 + fTemp591) + fTemp590);
			fRec1288[0] = (fRec1289[0] + fRec1288[1]);
			fRec1286[0] = fRec1288[0];
			double fRec1287 = fRec1290;
			fRec1285[0] = (fTemp588 + (fTemp589 + (fRec1287 + fRec1285[1])));
			fRec1283[0] = fRec1285[0];
			double fRec1284 = (fTemp588 + (fRec1287 + fTemp589));
			fRec1282[0] = (fRec1283[0] + fRec1282[1]);
			fRec1280[0] = fRec1282[0];
			double fRec1281 = fRec1284;
			double fTemp593 = (fConst87 * (((27705956820000.0 * fTemp23) + (11497241340000.0 * fTemp21)) - (27702457520000.0 * fTemp22)));
			double fTemp594 = (fConst88 * fRec1292[1]);
			fRec1294[0] = (fTemp593 + (fRec1294[1] + fTemp594));
			fRec1292[0] = fRec1294[0];
			double fRec1293 = (fTemp594 + fTemp593);
			fVec27[(IOTA & 127)] = ((42947684670000.0 * fTemp58) + (fRec1251 + (fRec1266 + (fRec1275 + (fRec1281 + fRec1293)))));
			output27[i] = FAUSTFLOAT((0.96133694670280023 * (fRec0[0] * fVec27[((IOTA - iConst93) & 127)])));
			double fTemp595 = (fConst95 * fRec1295[1]);
			double fTemp596 = (fConst97 * fRec1298[1]);
			double fTemp597 = (fConst98 * fRec1301[1]);
			double fTemp598 = (fConst100 * (((3652329132000.0 * fTemp16) + (3724677737000.0 * fTemp15)) - ((3160176891000.0 * fTemp10) + ((142242549800.0 * fTemp17) + ((4491655806000.0 * fTemp14) + ((249378163100.0 * fTemp13) + ((242703931700.0 * fTemp12) + (40407339560000.0 * fTemp11))))))));
			double fTemp599 = (fConst101 * fRec1304[1]);
			double fTemp600 = (fConst102 * fRec1307[1]);
			fRec1309[0] = (fTemp598 + (fTemp599 + (fRec1309[1] + fTemp600)));
			fRec1307[0] = fRec1309[0];
			double fRec1308 = ((fTemp600 + fTemp599) + fTemp598);
			fRec1306[0] = (fRec1307[0] + fRec1306[1]);
			fRec1304[0] = fRec1306[0];
			double fRec1305 = fRec1308;
			fRec1303[0] = (fTemp596 + (fTemp597 + (fRec1305 + fRec1303[1])));
			fRec1301[0] = fRec1303[0];
			double fRec1302 = (fTemp596 + (fRec1305 + fTemp597));
			fRec1300[0] = (fRec1301[0] + fRec1300[1]);
			fRec1298[0] = fRec1300[0];
			double fRec1299 = fRec1302;
			fRec1297[0] = (fTemp595 + (fRec1299 + fRec1297[1]));
			fRec1295[0] = fRec1297[0];
			double fRec1296 = (fRec1299 + fTemp595);
			double fTemp601 = (fConst104 * fRec1310[1]);
			double fTemp602 = (fConst105 * fRec1313[1]);
			double fTemp603 = (fConst107 * (((2810298775000.0 * fTemp33) + ((3218713986000.0 * fTemp32) + (((985961837600.0 * fTemp29) + ((2252348004000.0 * fTemp26) + (616460660200.0 * fTemp28))) + (19802714940000.0 * fTemp31)))) - ((1763205717000.0 * fTemp27) + (3956744149000.0 * fTemp30))));
			double fTemp604 = (fConst108 * fRec1316[1]);
			double fTemp605 = (fConst109 * fRec1319[1]);
			fRec1321[0] = (fTemp603 + (fTemp604 + (fRec1321[1] + fTemp605)));
			fRec1319[0] = fRec1321[0];
			double fRec1320 = ((fTemp605 + fTemp604) + fTemp603);
			fRec1318[0] = (fRec1319[0] + fRec1318[1]);
			fRec1316[0] = fRec1318[0];
			double fRec1317 = fRec1320;
			fRec1315[0] = (fTemp601 + (fTemp602 + (fRec1317 + fRec1315[1])));
			fRec1313[0] = fRec1315[0];
			double fRec1314 = (fTemp601 + (fRec1317 + fTemp602));
			fRec1312[0] = (fRec1313[0] + fRec1312[1]);
			fRec1310[0] = fRec1312[0];
			double fRec1311 = fRec1314;
			double fTemp606 = (fConst111 * fRec1322[1]);
			double fTemp607 = (fConst113 * (((((499371331500.0 * fTemp48) + (2554956198000.0 * fTemp49)) + (107313433000000.0 * fTemp54)) + (872904294700.0 * fTemp51)) - (((2157079359000.0 * fTemp53) + (1240901618000.0 * fTemp50)) + (592819960100.0 * fTemp52))));
			double fTemp608 = (fConst114 * fRec1325[1]);
			double fTemp609 = (fConst115 * fRec1328[1]);
			fRec1330[0] = (fTemp607 + (fTemp608 + (fRec1330[1] + fTemp609)));
			fRec1328[0] = fRec1330[0];
			double fRec1329 = ((fTemp609 + fTemp608) + fTemp607);
			fRec1327[0] = (fRec1328[0] + fRec1327[1]);
			fRec1325[0] = fRec1327[0];
			double fRec1326 = fRec1329;
			fRec1324[0] = (fTemp606 + (fRec1326 + fRec1324[1]));
			fRec1322[0] = fRec1324[0];
			double fRec1323 = (fRec1326 + fTemp606);
			double fTemp610 = (fConst117 * (((314573221100.0 * fTemp23) + (113174517000000.0 * fTemp21)) - (78401142850.0 * fTemp22)));
			double fTemp611 = (fConst118 * fRec1331[1]);
			fRec1333[0] = (fTemp610 + (fRec1333[1] + fTemp611));
			fRec1331[0] = fRec1333[0];
			double fRec1332 = (fTemp611 + fTemp610);
			double fTemp612 = (fConst120 * ((31005400340.0 * fTemp40) - (((805417552500.0 * fTemp42) + ((2273875403000.0 * fTemp39) + (37023066540000.0 * fTemp41))) + (1260307253000.0 * fTemp43))));
			double fTemp613 = (fConst121 * fRec1334[1]);
			double fTemp614 = (fConst122 * fRec1337[1]);
			fRec1339[0] = (fTemp612 + (fTemp613 + (fRec1339[1] + fTemp614)));
			fRec1337[0] = fRec1339[0];
			double fRec1338 = ((fTemp614 + fTemp613) + fTemp612);
			fRec1336[0] = (fRec1337[0] + fRec1336[1]);
			fRec1334[0] = fRec1336[0];
			double fRec1335 = fRec1338;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((fRec1296 + (fRec1311 + (fRec1323 + (fRec1332 + fRec1335)))) - (3784480838000.0 * fTemp58))));
			fRec0[1] = fRec0[0];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec57[1] = fRec57[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec75[2] = fRec75[1];
			fRec75[1] = fRec75[0];
			fRec76[2] = fRec76[1];
			fRec76[1] = fRec76[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec63[1] = fRec63[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			IOTA = (IOTA + 1);
			fRec91[1] = fRec91[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			fRec80[1] = fRec80[0];
			fRec100[1] = fRec100[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec92[1] = fRec92[0];
			fRec106[1] = fRec106[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fRec101[1] = fRec101[0];
			fRec121[1] = fRec121[0];
			fRec119[1] = fRec119[0];
			fRec118[1] = fRec118[0];
			fRec116[1] = fRec116[0];
			fRec115[1] = fRec115[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec110[1] = fRec110[0];
			fRec109[1] = fRec109[0];
			fRec107[1] = fRec107[0];
			fRec124[1] = fRec124[0];
			fRec122[1] = fRec122[0];
			fRec139[1] = fRec139[0];
			fRec137[1] = fRec137[0];
			fRec136[1] = fRec136[0];
			fRec134[1] = fRec134[0];
			fRec133[1] = fRec133[0];
			fRec131[1] = fRec131[0];
			fRec130[1] = fRec130[0];
			fRec128[1] = fRec128[0];
			fRec127[1] = fRec127[0];
			fRec125[1] = fRec125[0];
			fRec151[1] = fRec151[0];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fRec146[1] = fRec146[0];
			fRec145[1] = fRec145[0];
			fRec143[1] = fRec143[0];
			fRec142[1] = fRec142[0];
			fRec140[1] = fRec140[0];
			fRec160[1] = fRec160[0];
			fRec158[1] = fRec158[0];
			fRec157[1] = fRec157[0];
			fRec155[1] = fRec155[0];
			fRec154[1] = fRec154[0];
			fRec152[1] = fRec152[0];
			fRec163[1] = fRec163[0];
			fRec161[1] = fRec161[0];
			fRec169[1] = fRec169[0];
			fRec167[1] = fRec167[0];
			fRec166[1] = fRec166[0];
			fRec164[1] = fRec164[0];
			fRec175[1] = fRec175[0];
			fRec173[1] = fRec173[0];
			fRec172[1] = fRec172[0];
			fRec170[1] = fRec170[0];
			fRec178[1] = fRec178[0];
			fRec176[1] = fRec176[0];
			fRec193[1] = fRec193[0];
			fRec191[1] = fRec191[0];
			fRec190[1] = fRec190[0];
			fRec188[1] = fRec188[0];
			fRec187[1] = fRec187[0];
			fRec185[1] = fRec185[0];
			fRec184[1] = fRec184[0];
			fRec182[1] = fRec182[0];
			fRec181[1] = fRec181[0];
			fRec179[1] = fRec179[0];
			fRec202[1] = fRec202[0];
			fRec200[1] = fRec200[0];
			fRec199[1] = fRec199[0];
			fRec197[1] = fRec197[0];
			fRec196[1] = fRec196[0];
			fRec194[1] = fRec194[0];
			fRec214[1] = fRec214[0];
			fRec212[1] = fRec212[0];
			fRec211[1] = fRec211[0];
			fRec209[1] = fRec209[0];
			fRec208[1] = fRec208[0];
			fRec206[1] = fRec206[0];
			fRec205[1] = fRec205[0];
			fRec203[1] = fRec203[0];
			fRec229[1] = fRec229[0];
			fRec227[1] = fRec227[0];
			fRec226[1] = fRec226[0];
			fRec224[1] = fRec224[0];
			fRec223[1] = fRec223[0];
			fRec221[1] = fRec221[0];
			fRec220[1] = fRec220[0];
			fRec218[1] = fRec218[0];
			fRec217[1] = fRec217[0];
			fRec215[1] = fRec215[0];
			fRec241[1] = fRec241[0];
			fRec239[1] = fRec239[0];
			fRec238[1] = fRec238[0];
			fRec236[1] = fRec236[0];
			fRec235[1] = fRec235[0];
			fRec233[1] = fRec233[0];
			fRec232[1] = fRec232[0];
			fRec230[1] = fRec230[0];
			fRec250[1] = fRec250[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec245[1] = fRec245[0];
			fRec244[1] = fRec244[0];
			fRec242[1] = fRec242[0];
			fRec253[1] = fRec253[0];
			fRec251[1] = fRec251[0];
			fRec259[1] = fRec259[0];
			fRec257[1] = fRec257[0];
			fRec256[1] = fRec256[0];
			fRec254[1] = fRec254[0];
			fRec274[1] = fRec274[0];
			fRec272[1] = fRec272[0];
			fRec271[1] = fRec271[0];
			fRec269[1] = fRec269[0];
			fRec268[1] = fRec268[0];
			fRec266[1] = fRec266[0];
			fRec265[1] = fRec265[0];
			fRec263[1] = fRec263[0];
			fRec262[1] = fRec262[0];
			fRec260[1] = fRec260[0];
			fRec286[1] = fRec286[0];
			fRec284[1] = fRec284[0];
			fRec283[1] = fRec283[0];
			fRec281[1] = fRec281[0];
			fRec280[1] = fRec280[0];
			fRec278[1] = fRec278[0];
			fRec277[1] = fRec277[0];
			fRec275[1] = fRec275[0];
			fRec295[1] = fRec295[0];
			fRec293[1] = fRec293[0];
			fRec292[1] = fRec292[0];
			fRec290[1] = fRec290[0];
			fRec289[1] = fRec289[0];
			fRec287[1] = fRec287[0];
			fRec298[1] = fRec298[0];
			fRec296[1] = fRec296[0];
			fRec304[1] = fRec304[0];
			fRec302[1] = fRec302[0];
			fRec301[1] = fRec301[0];
			fRec299[1] = fRec299[0];
			fRec319[1] = fRec319[0];
			fRec317[1] = fRec317[0];
			fRec316[1] = fRec316[0];
			fRec314[1] = fRec314[0];
			fRec313[1] = fRec313[0];
			fRec311[1] = fRec311[0];
			fRec310[1] = fRec310[0];
			fRec308[1] = fRec308[0];
			fRec307[1] = fRec307[0];
			fRec305[1] = fRec305[0];
			fRec328[1] = fRec328[0];
			fRec326[1] = fRec326[0];
			fRec325[1] = fRec325[0];
			fRec323[1] = fRec323[0];
			fRec322[1] = fRec322[0];
			fRec320[1] = fRec320[0];
			fRec331[1] = fRec331[0];
			fRec329[1] = fRec329[0];
			fRec337[1] = fRec337[0];
			fRec335[1] = fRec335[0];
			fRec334[1] = fRec334[0];
			fRec332[1] = fRec332[0];
			fRec349[1] = fRec349[0];
			fRec347[1] = fRec347[0];
			fRec346[1] = fRec346[0];
			fRec344[1] = fRec344[0];
			fRec343[1] = fRec343[0];
			fRec341[1] = fRec341[0];
			fRec340[1] = fRec340[0];
			fRec338[1] = fRec338[0];
			fRec358[1] = fRec358[0];
			fRec356[1] = fRec356[0];
			fRec355[1] = fRec355[0];
			fRec353[1] = fRec353[0];
			fRec352[1] = fRec352[0];
			fRec350[1] = fRec350[0];
			fRec364[1] = fRec364[0];
			fRec362[1] = fRec362[0];
			fRec361[1] = fRec361[0];
			fRec359[1] = fRec359[0];
			fRec367[1] = fRec367[0];
			fRec365[1] = fRec365[0];
			fRec379[1] = fRec379[0];
			fRec377[1] = fRec377[0];
			fRec376[1] = fRec376[0];
			fRec374[1] = fRec374[0];
			fRec373[1] = fRec373[0];
			fRec371[1] = fRec371[0];
			fRec370[1] = fRec370[0];
			fRec368[1] = fRec368[0];
			fRec394[1] = fRec394[0];
			fRec392[1] = fRec392[0];
			fRec391[1] = fRec391[0];
			fRec389[1] = fRec389[0];
			fRec388[1] = fRec388[0];
			fRec386[1] = fRec386[0];
			fRec385[1] = fRec385[0];
			fRec383[1] = fRec383[0];
			fRec382[1] = fRec382[0];
			fRec380[1] = fRec380[0];
			fRec409[1] = fRec409[0];
			fRec407[1] = fRec407[0];
			fRec406[1] = fRec406[0];
			fRec404[1] = fRec404[0];
			fRec403[1] = fRec403[0];
			fRec401[1] = fRec401[0];
			fRec400[1] = fRec400[0];
			fRec398[1] = fRec398[0];
			fRec397[1] = fRec397[0];
			fRec395[1] = fRec395[0];
			fRec421[1] = fRec421[0];
			fRec419[1] = fRec419[0];
			fRec418[1] = fRec418[0];
			fRec416[1] = fRec416[0];
			fRec415[1] = fRec415[0];
			fRec413[1] = fRec413[0];
			fRec412[1] = fRec412[0];
			fRec410[1] = fRec410[0];
			fRec430[1] = fRec430[0];
			fRec428[1] = fRec428[0];
			fRec427[1] = fRec427[0];
			fRec425[1] = fRec425[0];
			fRec424[1] = fRec424[0];
			fRec422[1] = fRec422[0];
			fRec433[1] = fRec433[0];
			fRec431[1] = fRec431[0];
			fRec439[1] = fRec439[0];
			fRec437[1] = fRec437[0];
			fRec436[1] = fRec436[0];
			fRec434[1] = fRec434[0];
			fRec454[1] = fRec454[0];
			fRec452[1] = fRec452[0];
			fRec451[1] = fRec451[0];
			fRec449[1] = fRec449[0];
			fRec448[1] = fRec448[0];
			fRec446[1] = fRec446[0];
			fRec445[1] = fRec445[0];
			fRec443[1] = fRec443[0];
			fRec442[1] = fRec442[0];
			fRec440[1] = fRec440[0];
			fRec457[1] = fRec457[0];
			fRec455[1] = fRec455[0];
			fRec463[1] = fRec463[0];
			fRec461[1] = fRec461[0];
			fRec460[1] = fRec460[0];
			fRec458[1] = fRec458[0];
			fRec472[1] = fRec472[0];
			fRec470[1] = fRec470[0];
			fRec469[1] = fRec469[0];
			fRec467[1] = fRec467[0];
			fRec466[1] = fRec466[0];
			fRec464[1] = fRec464[0];
			fRec484[1] = fRec484[0];
			fRec482[1] = fRec482[0];
			fRec481[1] = fRec481[0];
			fRec479[1] = fRec479[0];
			fRec478[1] = fRec478[0];
			fRec476[1] = fRec476[0];
			fRec475[1] = fRec475[0];
			fRec473[1] = fRec473[0];
			fRec499[1] = fRec499[0];
			fRec497[1] = fRec497[0];
			fRec496[1] = fRec496[0];
			fRec494[1] = fRec494[0];
			fRec493[1] = fRec493[0];
			fRec491[1] = fRec491[0];
			fRec490[1] = fRec490[0];
			fRec488[1] = fRec488[0];
			fRec487[1] = fRec487[0];
			fRec485[1] = fRec485[0];
			fRec511[1] = fRec511[0];
			fRec509[1] = fRec509[0];
			fRec508[1] = fRec508[0];
			fRec506[1] = fRec506[0];
			fRec505[1] = fRec505[0];
			fRec503[1] = fRec503[0];
			fRec502[1] = fRec502[0];
			fRec500[1] = fRec500[0];
			fRec520[1] = fRec520[0];
			fRec518[1] = fRec518[0];
			fRec517[1] = fRec517[0];
			fRec515[1] = fRec515[0];
			fRec514[1] = fRec514[0];
			fRec512[1] = fRec512[0];
			fRec523[1] = fRec523[0];
			fRec521[1] = fRec521[0];
			fRec529[1] = fRec529[0];
			fRec527[1] = fRec527[0];
			fRec526[1] = fRec526[0];
			fRec524[1] = fRec524[0];
			fRec544[1] = fRec544[0];
			fRec542[1] = fRec542[0];
			fRec541[1] = fRec541[0];
			fRec539[1] = fRec539[0];
			fRec538[1] = fRec538[0];
			fRec536[1] = fRec536[0];
			fRec535[1] = fRec535[0];
			fRec533[1] = fRec533[0];
			fRec532[1] = fRec532[0];
			fRec530[1] = fRec530[0];
			fRec556[1] = fRec556[0];
			fRec554[1] = fRec554[0];
			fRec553[1] = fRec553[0];
			fRec551[1] = fRec551[0];
			fRec550[1] = fRec550[0];
			fRec548[1] = fRec548[0];
			fRec547[1] = fRec547[0];
			fRec545[1] = fRec545[0];
			fRec565[1] = fRec565[0];
			fRec563[1] = fRec563[0];
			fRec562[1] = fRec562[0];
			fRec560[1] = fRec560[0];
			fRec559[1] = fRec559[0];
			fRec557[1] = fRec557[0];
			fRec568[1] = fRec568[0];
			fRec566[1] = fRec566[0];
			fRec574[1] = fRec574[0];
			fRec572[1] = fRec572[0];
			fRec571[1] = fRec571[0];
			fRec569[1] = fRec569[0];
			fRec589[1] = fRec589[0];
			fRec587[1] = fRec587[0];
			fRec586[1] = fRec586[0];
			fRec584[1] = fRec584[0];
			fRec583[1] = fRec583[0];
			fRec581[1] = fRec581[0];
			fRec580[1] = fRec580[0];
			fRec578[1] = fRec578[0];
			fRec577[1] = fRec577[0];
			fRec575[1] = fRec575[0];
			fRec601[1] = fRec601[0];
			fRec599[1] = fRec599[0];
			fRec598[1] = fRec598[0];
			fRec596[1] = fRec596[0];
			fRec595[1] = fRec595[0];
			fRec593[1] = fRec593[0];
			fRec592[1] = fRec592[0];
			fRec590[1] = fRec590[0];
			fRec610[1] = fRec610[0];
			fRec608[1] = fRec608[0];
			fRec607[1] = fRec607[0];
			fRec605[1] = fRec605[0];
			fRec604[1] = fRec604[0];
			fRec602[1] = fRec602[0];
			fRec613[1] = fRec613[0];
			fRec611[1] = fRec611[0];
			fRec619[1] = fRec619[0];
			fRec617[1] = fRec617[0];
			fRec616[1] = fRec616[0];
			fRec614[1] = fRec614[0];
			fRec634[1] = fRec634[0];
			fRec632[1] = fRec632[0];
			fRec631[1] = fRec631[0];
			fRec629[1] = fRec629[0];
			fRec628[1] = fRec628[0];
			fRec626[1] = fRec626[0];
			fRec625[1] = fRec625[0];
			fRec623[1] = fRec623[0];
			fRec622[1] = fRec622[0];
			fRec620[1] = fRec620[0];
			fRec637[1] = fRec637[0];
			fRec635[1] = fRec635[0];
			fRec643[1] = fRec643[0];
			fRec641[1] = fRec641[0];
			fRec640[1] = fRec640[0];
			fRec638[1] = fRec638[0];
			fRec652[1] = fRec652[0];
			fRec650[1] = fRec650[0];
			fRec649[1] = fRec649[0];
			fRec647[1] = fRec647[0];
			fRec646[1] = fRec646[0];
			fRec644[1] = fRec644[0];
			fRec664[1] = fRec664[0];
			fRec662[1] = fRec662[0];
			fRec661[1] = fRec661[0];
			fRec659[1] = fRec659[0];
			fRec658[1] = fRec658[0];
			fRec656[1] = fRec656[0];
			fRec655[1] = fRec655[0];
			fRec653[1] = fRec653[0];
			fRec667[1] = fRec667[0];
			fRec665[1] = fRec665[0];
			fRec682[1] = fRec682[0];
			fRec680[1] = fRec680[0];
			fRec679[1] = fRec679[0];
			fRec677[1] = fRec677[0];
			fRec676[1] = fRec676[0];
			fRec674[1] = fRec674[0];
			fRec673[1] = fRec673[0];
			fRec671[1] = fRec671[0];
			fRec670[1] = fRec670[0];
			fRec668[1] = fRec668[0];
			fRec688[1] = fRec688[0];
			fRec686[1] = fRec686[0];
			fRec685[1] = fRec685[0];
			fRec683[1] = fRec683[0];
			fRec697[1] = fRec697[0];
			fRec695[1] = fRec695[0];
			fRec694[1] = fRec694[0];
			fRec692[1] = fRec692[0];
			fRec691[1] = fRec691[0];
			fRec689[1] = fRec689[0];
			fRec709[1] = fRec709[0];
			fRec707[1] = fRec707[0];
			fRec706[1] = fRec706[0];
			fRec704[1] = fRec704[0];
			fRec703[1] = fRec703[0];
			fRec701[1] = fRec701[0];
			fRec700[1] = fRec700[0];
			fRec698[1] = fRec698[0];
			fRec721[1] = fRec721[0];
			fRec719[1] = fRec719[0];
			fRec718[1] = fRec718[0];
			fRec716[1] = fRec716[0];
			fRec715[1] = fRec715[0];
			fRec713[1] = fRec713[0];
			fRec712[1] = fRec712[0];
			fRec710[1] = fRec710[0];
			fRec736[1] = fRec736[0];
			fRec734[1] = fRec734[0];
			fRec733[1] = fRec733[0];
			fRec731[1] = fRec731[0];
			fRec730[1] = fRec730[0];
			fRec728[1] = fRec728[0];
			fRec727[1] = fRec727[0];
			fRec725[1] = fRec725[0];
			fRec724[1] = fRec724[0];
			fRec722[1] = fRec722[0];
			fRec745[1] = fRec745[0];
			fRec743[1] = fRec743[0];
			fRec742[1] = fRec742[0];
			fRec740[1] = fRec740[0];
			fRec739[1] = fRec739[0];
			fRec737[1] = fRec737[0];
			fRec748[1] = fRec748[0];
			fRec746[1] = fRec746[0];
			fRec754[1] = fRec754[0];
			fRec752[1] = fRec752[0];
			fRec751[1] = fRec751[0];
			fRec749[1] = fRec749[0];
			fRec760[1] = fRec760[0];
			fRec758[1] = fRec758[0];
			fRec757[1] = fRec757[0];
			fRec755[1] = fRec755[0];
			fRec763[1] = fRec763[0];
			fRec761[1] = fRec761[0];
			fRec778[1] = fRec778[0];
			fRec776[1] = fRec776[0];
			fRec775[1] = fRec775[0];
			fRec773[1] = fRec773[0];
			fRec772[1] = fRec772[0];
			fRec770[1] = fRec770[0];
			fRec769[1] = fRec769[0];
			fRec767[1] = fRec767[0];
			fRec766[1] = fRec766[0];
			fRec764[1] = fRec764[0];
			fRec787[1] = fRec787[0];
			fRec785[1] = fRec785[0];
			fRec784[1] = fRec784[0];
			fRec782[1] = fRec782[0];
			fRec781[1] = fRec781[0];
			fRec779[1] = fRec779[0];
			fRec799[1] = fRec799[0];
			fRec797[1] = fRec797[0];
			fRec796[1] = fRec796[0];
			fRec794[1] = fRec794[0];
			fRec793[1] = fRec793[0];
			fRec791[1] = fRec791[0];
			fRec790[1] = fRec790[0];
			fRec788[1] = fRec788[0];
			fRec811[1] = fRec811[0];
			fRec809[1] = fRec809[0];
			fRec808[1] = fRec808[0];
			fRec806[1] = fRec806[0];
			fRec805[1] = fRec805[0];
			fRec803[1] = fRec803[0];
			fRec802[1] = fRec802[0];
			fRec800[1] = fRec800[0];
			fRec826[1] = fRec826[0];
			fRec824[1] = fRec824[0];
			fRec823[1] = fRec823[0];
			fRec821[1] = fRec821[0];
			fRec820[1] = fRec820[0];
			fRec818[1] = fRec818[0];
			fRec817[1] = fRec817[0];
			fRec815[1] = fRec815[0];
			fRec814[1] = fRec814[0];
			fRec812[1] = fRec812[0];
			fRec832[1] = fRec832[0];
			fRec830[1] = fRec830[0];
			fRec829[1] = fRec829[0];
			fRec827[1] = fRec827[0];
			fRec841[1] = fRec841[0];
			fRec839[1] = fRec839[0];
			fRec838[1] = fRec838[0];
			fRec836[1] = fRec836[0];
			fRec835[1] = fRec835[0];
			fRec833[1] = fRec833[0];
			fRec844[1] = fRec844[0];
			fRec842[1] = fRec842[0];
			fRec859[1] = fRec859[0];
			fRec857[1] = fRec857[0];
			fRec856[1] = fRec856[0];
			fRec854[1] = fRec854[0];
			fRec853[1] = fRec853[0];
			fRec851[1] = fRec851[0];
			fRec850[1] = fRec850[0];
			fRec848[1] = fRec848[0];
			fRec847[1] = fRec847[0];
			fRec845[1] = fRec845[0];
			fRec871[1] = fRec871[0];
			fRec869[1] = fRec869[0];
			fRec868[1] = fRec868[0];
			fRec866[1] = fRec866[0];
			fRec865[1] = fRec865[0];
			fRec863[1] = fRec863[0];
			fRec862[1] = fRec862[0];
			fRec860[1] = fRec860[0];
			fRec880[1] = fRec880[0];
			fRec878[1] = fRec878[0];
			fRec877[1] = fRec877[0];
			fRec875[1] = fRec875[0];
			fRec874[1] = fRec874[0];
			fRec872[1] = fRec872[0];
			fRec883[1] = fRec883[0];
			fRec881[1] = fRec881[0];
			fRec889[1] = fRec889[0];
			fRec887[1] = fRec887[0];
			fRec886[1] = fRec886[0];
			fRec884[1] = fRec884[0];
			fRec901[1] = fRec901[0];
			fRec899[1] = fRec899[0];
			fRec898[1] = fRec898[0];
			fRec896[1] = fRec896[0];
			fRec895[1] = fRec895[0];
			fRec893[1] = fRec893[0];
			fRec892[1] = fRec892[0];
			fRec890[1] = fRec890[0];
			fRec910[1] = fRec910[0];
			fRec908[1] = fRec908[0];
			fRec907[1] = fRec907[0];
			fRec905[1] = fRec905[0];
			fRec904[1] = fRec904[0];
			fRec902[1] = fRec902[0];
			fRec916[1] = fRec916[0];
			fRec914[1] = fRec914[0];
			fRec913[1] = fRec913[0];
			fRec911[1] = fRec911[0];
			fRec919[1] = fRec919[0];
			fRec917[1] = fRec917[0];
			fRec934[1] = fRec934[0];
			fRec932[1] = fRec932[0];
			fRec931[1] = fRec931[0];
			fRec929[1] = fRec929[0];
			fRec928[1] = fRec928[0];
			fRec926[1] = fRec926[0];
			fRec925[1] = fRec925[0];
			fRec923[1] = fRec923[0];
			fRec922[1] = fRec922[0];
			fRec920[1] = fRec920[0];
			fRec949[1] = fRec949[0];
			fRec947[1] = fRec947[0];
			fRec946[1] = fRec946[0];
			fRec944[1] = fRec944[0];
			fRec943[1] = fRec943[0];
			fRec941[1] = fRec941[0];
			fRec940[1] = fRec940[0];
			fRec938[1] = fRec938[0];
			fRec937[1] = fRec937[0];
			fRec935[1] = fRec935[0];
			fRec961[1] = fRec961[0];
			fRec959[1] = fRec959[0];
			fRec958[1] = fRec958[0];
			fRec956[1] = fRec956[0];
			fRec955[1] = fRec955[0];
			fRec953[1] = fRec953[0];
			fRec952[1] = fRec952[0];
			fRec950[1] = fRec950[0];
			fRec967[1] = fRec967[0];
			fRec965[1] = fRec965[0];
			fRec964[1] = fRec964[0];
			fRec962[1] = fRec962[0];
			fRec976[1] = fRec976[0];
			fRec974[1] = fRec974[0];
			fRec973[1] = fRec973[0];
			fRec971[1] = fRec971[0];
			fRec970[1] = fRec970[0];
			fRec968[1] = fRec968[0];
			fRec979[1] = fRec979[0];
			fRec977[1] = fRec977[0];
			fRec994[1] = fRec994[0];
			fRec992[1] = fRec992[0];
			fRec991[1] = fRec991[0];
			fRec989[1] = fRec989[0];
			fRec988[1] = fRec988[0];
			fRec986[1] = fRec986[0];
			fRec985[1] = fRec985[0];
			fRec983[1] = fRec983[0];
			fRec982[1] = fRec982[0];
			fRec980[1] = fRec980[0];
			fRec1006[1] = fRec1006[0];
			fRec1004[1] = fRec1004[0];
			fRec1003[1] = fRec1003[0];
			fRec1001[1] = fRec1001[0];
			fRec1000[1] = fRec1000[0];
			fRec998[1] = fRec998[0];
			fRec997[1] = fRec997[0];
			fRec995[1] = fRec995[0];
			fRec1015[1] = fRec1015[0];
			fRec1013[1] = fRec1013[0];
			fRec1012[1] = fRec1012[0];
			fRec1010[1] = fRec1010[0];
			fRec1009[1] = fRec1009[0];
			fRec1007[1] = fRec1007[0];
			fRec1018[1] = fRec1018[0];
			fRec1016[1] = fRec1016[0];
			fRec1024[1] = fRec1024[0];
			fRec1022[1] = fRec1022[0];
			fRec1021[1] = fRec1021[0];
			fRec1019[1] = fRec1019[0];
			fRec1039[1] = fRec1039[0];
			fRec1037[1] = fRec1037[0];
			fRec1036[1] = fRec1036[0];
			fRec1034[1] = fRec1034[0];
			fRec1033[1] = fRec1033[0];
			fRec1031[1] = fRec1031[0];
			fRec1030[1] = fRec1030[0];
			fRec1028[1] = fRec1028[0];
			fRec1027[1] = fRec1027[0];
			fRec1025[1] = fRec1025[0];
			fRec1042[1] = fRec1042[0];
			fRec1040[1] = fRec1040[0];
			fRec1054[1] = fRec1054[0];
			fRec1052[1] = fRec1052[0];
			fRec1051[1] = fRec1051[0];
			fRec1049[1] = fRec1049[0];
			fRec1048[1] = fRec1048[0];
			fRec1046[1] = fRec1046[0];
			fRec1045[1] = fRec1045[0];
			fRec1043[1] = fRec1043[0];
			fRec1060[1] = fRec1060[0];
			fRec1058[1] = fRec1058[0];
			fRec1057[1] = fRec1057[0];
			fRec1055[1] = fRec1055[0];
			fRec1069[1] = fRec1069[0];
			fRec1067[1] = fRec1067[0];
			fRec1066[1] = fRec1066[0];
			fRec1064[1] = fRec1064[0];
			fRec1063[1] = fRec1063[0];
			fRec1061[1] = fRec1061[0];
			fRec1078[1] = fRec1078[0];
			fRec1076[1] = fRec1076[0];
			fRec1075[1] = fRec1075[0];
			fRec1073[1] = fRec1073[0];
			fRec1072[1] = fRec1072[0];
			fRec1070[1] = fRec1070[0];
			fRec1081[1] = fRec1081[0];
			fRec1079[1] = fRec1079[0];
			fRec1096[1] = fRec1096[0];
			fRec1094[1] = fRec1094[0];
			fRec1093[1] = fRec1093[0];
			fRec1091[1] = fRec1091[0];
			fRec1090[1] = fRec1090[0];
			fRec1088[1] = fRec1088[0];
			fRec1087[1] = fRec1087[0];
			fRec1085[1] = fRec1085[0];
			fRec1084[1] = fRec1084[0];
			fRec1082[1] = fRec1082[0];
			fRec1102[1] = fRec1102[0];
			fRec1100[1] = fRec1100[0];
			fRec1099[1] = fRec1099[0];
			fRec1097[1] = fRec1097[0];
			fRec1114[1] = fRec1114[0];
			fRec1112[1] = fRec1112[0];
			fRec1111[1] = fRec1111[0];
			fRec1109[1] = fRec1109[0];
			fRec1108[1] = fRec1108[0];
			fRec1106[1] = fRec1106[0];
			fRec1105[1] = fRec1105[0];
			fRec1103[1] = fRec1103[0];
			fRec1126[1] = fRec1126[0];
			fRec1124[1] = fRec1124[0];
			fRec1123[1] = fRec1123[0];
			fRec1121[1] = fRec1121[0];
			fRec1120[1] = fRec1120[0];
			fRec1118[1] = fRec1118[0];
			fRec1117[1] = fRec1117[0];
			fRec1115[1] = fRec1115[0];
			fRec1141[1] = fRec1141[0];
			fRec1139[1] = fRec1139[0];
			fRec1138[1] = fRec1138[0];
			fRec1136[1] = fRec1136[0];
			fRec1135[1] = fRec1135[0];
			fRec1133[1] = fRec1133[0];
			fRec1132[1] = fRec1132[0];
			fRec1130[1] = fRec1130[0];
			fRec1129[1] = fRec1129[0];
			fRec1127[1] = fRec1127[0];
			fRec1150[1] = fRec1150[0];
			fRec1148[1] = fRec1148[0];
			fRec1147[1] = fRec1147[0];
			fRec1145[1] = fRec1145[0];
			fRec1144[1] = fRec1144[0];
			fRec1142[1] = fRec1142[0];
			fRec1153[1] = fRec1153[0];
			fRec1151[1] = fRec1151[0];
			fRec1159[1] = fRec1159[0];
			fRec1157[1] = fRec1157[0];
			fRec1156[1] = fRec1156[0];
			fRec1154[1] = fRec1154[0];
			fRec1174[1] = fRec1174[0];
			fRec1172[1] = fRec1172[0];
			fRec1171[1] = fRec1171[0];
			fRec1169[1] = fRec1169[0];
			fRec1168[1] = fRec1168[0];
			fRec1166[1] = fRec1166[0];
			fRec1165[1] = fRec1165[0];
			fRec1163[1] = fRec1163[0];
			fRec1162[1] = fRec1162[0];
			fRec1160[1] = fRec1160[0];
			fRec1183[1] = fRec1183[0];
			fRec1181[1] = fRec1181[0];
			fRec1180[1] = fRec1180[0];
			fRec1178[1] = fRec1178[0];
			fRec1177[1] = fRec1177[0];
			fRec1175[1] = fRec1175[0];
			fRec1189[1] = fRec1189[0];
			fRec1187[1] = fRec1187[0];
			fRec1186[1] = fRec1186[0];
			fRec1184[1] = fRec1184[0];
			fRec1201[1] = fRec1201[0];
			fRec1199[1] = fRec1199[0];
			fRec1198[1] = fRec1198[0];
			fRec1196[1] = fRec1196[0];
			fRec1195[1] = fRec1195[0];
			fRec1193[1] = fRec1193[0];
			fRec1192[1] = fRec1192[0];
			fRec1190[1] = fRec1190[0];
			fRec1204[1] = fRec1204[0];
			fRec1202[1] = fRec1202[0];
			fRec1219[1] = fRec1219[0];
			fRec1217[1] = fRec1217[0];
			fRec1216[1] = fRec1216[0];
			fRec1214[1] = fRec1214[0];
			fRec1213[1] = fRec1213[0];
			fRec1211[1] = fRec1211[0];
			fRec1210[1] = fRec1210[0];
			fRec1208[1] = fRec1208[0];
			fRec1207[1] = fRec1207[0];
			fRec1205[1] = fRec1205[0];
			fRec1231[1] = fRec1231[0];
			fRec1229[1] = fRec1229[0];
			fRec1228[1] = fRec1228[0];
			fRec1226[1] = fRec1226[0];
			fRec1225[1] = fRec1225[0];
			fRec1223[1] = fRec1223[0];
			fRec1222[1] = fRec1222[0];
			fRec1220[1] = fRec1220[0];
			fRec1240[1] = fRec1240[0];
			fRec1238[1] = fRec1238[0];
			fRec1237[1] = fRec1237[0];
			fRec1235[1] = fRec1235[0];
			fRec1234[1] = fRec1234[0];
			fRec1232[1] = fRec1232[0];
			fRec1243[1] = fRec1243[0];
			fRec1241[1] = fRec1241[0];
			fRec1249[1] = fRec1249[0];
			fRec1247[1] = fRec1247[0];
			fRec1246[1] = fRec1246[0];
			fRec1244[1] = fRec1244[0];
			fRec1264[1] = fRec1264[0];
			fRec1262[1] = fRec1262[0];
			fRec1261[1] = fRec1261[0];
			fRec1259[1] = fRec1259[0];
			fRec1258[1] = fRec1258[0];
			fRec1256[1] = fRec1256[0];
			fRec1255[1] = fRec1255[0];
			fRec1253[1] = fRec1253[0];
			fRec1252[1] = fRec1252[0];
			fRec1250[1] = fRec1250[0];
			fRec1273[1] = fRec1273[0];
			fRec1271[1] = fRec1271[0];
			fRec1270[1] = fRec1270[0];
			fRec1268[1] = fRec1268[0];
			fRec1267[1] = fRec1267[0];
			fRec1265[1] = fRec1265[0];
			fRec1279[1] = fRec1279[0];
			fRec1277[1] = fRec1277[0];
			fRec1276[1] = fRec1276[0];
			fRec1274[1] = fRec1274[0];
			fRec1291[1] = fRec1291[0];
			fRec1289[1] = fRec1289[0];
			fRec1288[1] = fRec1288[0];
			fRec1286[1] = fRec1286[0];
			fRec1285[1] = fRec1285[0];
			fRec1283[1] = fRec1283[0];
			fRec1282[1] = fRec1282[0];
			fRec1280[1] = fRec1280[0];
			fRec1294[1] = fRec1294[0];
			fRec1292[1] = fRec1292[0];
			fRec1309[1] = fRec1309[0];
			fRec1307[1] = fRec1307[0];
			fRec1306[1] = fRec1306[0];
			fRec1304[1] = fRec1304[0];
			fRec1303[1] = fRec1303[0];
			fRec1301[1] = fRec1301[0];
			fRec1300[1] = fRec1300[0];
			fRec1298[1] = fRec1298[0];
			fRec1297[1] = fRec1297[0];
			fRec1295[1] = fRec1295[0];
			fRec1321[1] = fRec1321[0];
			fRec1319[1] = fRec1319[0];
			fRec1318[1] = fRec1318[0];
			fRec1316[1] = fRec1316[0];
			fRec1315[1] = fRec1315[0];
			fRec1313[1] = fRec1313[0];
			fRec1312[1] = fRec1312[0];
			fRec1310[1] = fRec1310[0];
			fRec1330[1] = fRec1330[0];
			fRec1328[1] = fRec1328[0];
			fRec1327[1] = fRec1327[0];
			fRec1325[1] = fRec1325[0];
			fRec1324[1] = fRec1324[0];
			fRec1322[1] = fRec1322[0];
			fRec1333[1] = fRec1333[0];
			fRec1331[1] = fRec1331[0];
			fRec1339[1] = fRec1339[0];
			fRec1337[1] = fRec1337[0];
			fRec1336[1] = fRec1336[0];
			fRec1334[1] = fRec1334[0];
			
		}
		
	}

	
};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  	/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2	/* should be defined somewhere ?? */

#define EXTERNAL_VERSION    "0.64"
#define STR_SIZE            512

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <iostream>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#pragma warning (disable: 4334)
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

inline ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

inline void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

inline int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

inline void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

inline void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
        
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            zmap::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                delete (*it).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI* fGUI;
        FAUSTFLOAT* fZone;
        FAUSTFLOAT fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
                
        FAUSTFLOAT cache() { return fCache; }
        virtual void reflectZone() = 0;
};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem {
    
	uiCallback fCallback;
	void* fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Base class for timed items
 */

// For precise timestamped control
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <cmath>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_STOP = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return true; }
        virtual void stop_midi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }

};

#endif // __midi__
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
        LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = std::atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data is handled.
 ******************************************************************************/

class uiMidi {
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        
    public:
        
        uiMidi(midi* midi_out, bool input):fMidiOut(midi_out), fInputCtrl(input)
        {}
        virtual ~uiMidi()
        {}
    
};

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

// MIDI sync

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->start_sync(0);
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stop_sync(0);
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

class uiMidiProgChange : public uiMidiItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return std::pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*std::log(v)/std::log(2.0)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};


class uiMidiKeyPress : public uiMidiItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(0);
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <assert.h>
#include <cstdlib>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string index;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
        
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->index = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (std::strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

typedef std::map<std::string, pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems;
    
    std::string fVersion;
    std::string fOptions;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]
    
    bool isInput(const string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const string& type) { return (type == "hbargraph" || type == "vbargraph"); }

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
        
        if (fMetadatas.find("filename") != fMetadatas.end()) {
            fFileName = fMetadatas["filename"];
            fMetadatas.erase("filename");
        } else {
            fName = "";
        }
     
        if (fMetadatas.find("version") != fMetadatas.end()) {
            fVersion = fMetadatas["version"];
            fMetadatas.erase("version");
        } else {
            fVersion = "";
        }
        
        if (fMetadatas.find("options") != fMetadatas.end()) {
            fOptions = fMetadatas["options"];
            fMetadatas.erase("options");
        } else {
            fOptions = "";
        }
        
        if (fMetadatas.find("size") != fMetadatas.end()) {
            fDSPSize = std::atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = std::atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = std::atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
       
        fInputItems = 0;
        fOutputItems = 0;
        
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        
        int counterIn = 0;
        int counterOut = 0;
        
        // Prepare the fPathTable and init zone
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            // Meta data declaration for input items
            if (isInput(type)) {
                if ((*it)->address != "") {
                    fPathInputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fOutControl[counterOut]);
                }
                fOutControl[counterOut] = FAUSTFLOAT(0);
                counterOut++;
            }
        }
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        vector<itemInfo*>::iterator it;
        int item = 0;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            if (isInput((*it)->type)) {
                fInControl[item++] = STR2REAL((*it)->init);
            }
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (isInput(type)) {
                isInItem = true;
            } else if (isOutput(type)) {
                isOutItem = true;
            }
            
            // Meta data declaration for input items
            if (isInput(type)) {
                fInControl[counterIn] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                fOutControl[counterOut] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};


#endif

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingFreq)
        {
            instanceInit(samplingFreq);
        }
        virtual void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
{
    return 440.0 * std::pow(2.0, (note-69.0)/12.0);
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
        fInputsSlice = new FAUSTFLOAT*[dsp->getNumInputs()];
        fOutputsSlice = new FAUSTFLOAT*[dsp->getNumOutputs()];
    }
    virtual ~dsp_voice()
    {
        delete [] fInputsSlice;
        delete [] fOutputsSlice;
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            for (int chan = 0; chan < getNumInputs(); chan++) {
                fInputsSlice[chan] = &(inputs[chan][offset]);
            }
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fOutputsSlice[chan] = &(outputs[chan][offset]);
            }
            compute(slice, fInputsSlice, fOutputsSlice);
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), i+1);
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for Polyphonic DSP.
 */
class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
};

/**
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        inline int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = i;
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        inline int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = i;
                    goto result;
                }
            }

            {
                // Otherwise steal one
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
                        }
                    }
                }
            
                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    voice = voice_release;
                    goto result;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    voice = voice_playing;
                    goto result;
                } else {
                    assert(false);
                    return kNoVoice;
                }
            }
            
        result:
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fTrigger = true;    // So that envelop is always re-initialized
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp)
        {
            fDate = 0;

            // Create voices
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            decorator_dsp::init(samplingRate);
            fVoiceGroup->init(samplingRate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int samplingRate)
        {
            decorator_dsp::instanceConstants(samplingRate);
            fVoiceGroup->instanceConstants(samplingRate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

};

#endif // __poly_dsp__

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

struct Max_Meta3 : Meta
{
    string fName;
    void declare(const char* key, const char* value)
    {
        if ((strcmp("filename", key) == 0)) {
            fName = "com.grame." + string(value) + "~";
        }
    }
};

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector <t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    midi_handler* m_midiHandler;
#endif
#ifdef SOUNDFILE
    SoundUI* m_soundInterface;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0,1.0,f);}
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "Button(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

        void toString(char* buffer)
        {
            stringstream str;
            str << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }

		void setValue(FAUSTFLOAT f) {*fZone = range(fMin,fMax,f);}
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
    
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/

#define MULTI_SIZE  256

class mspUI : public UI
{
	private:

        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
       
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string, mspUIObject*>::iterator iterator;

		mspUI() 
        {
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
		virtual ~mspUI()
		{
            clear();
   		}
      
		void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
		}
        
        bool isMulti() { return fMultiControl > 0; }
    
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
		FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }

        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
    
        void displayControls()
        {
            iterator it;
            post((char*)"------- labels and ranges ----------");
            for (it = fUITable1.begin(); it != fUITable1.end(); it++) {
                char param[STR_SIZE];
                it->second->toString(param);
                post(param);
            }
            post((char*)"------- complete paths ----------");
            for (it = fUITable2.begin(); it != fUITable2.end(); it++) {
                post(it->first.c_str());
            }
            post((char*)"---------------------------------");
        }
    
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { return true; }
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { count++; }
    }
    return count;
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        float off = 0.0f;
        float on = 1.0f;
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: 
                    value = (float)ap[0].a_w.w_long;
                    break;
                
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            string str = num_val.str();
            char param_name[256];
            
            switch (ndigit - count_digit(str)) {
                case 0:
                    sprintf(param_name, "%s%s", prefix.c_str(), str.c_str());
                    break;
                case 1:
                    sprintf(param_name, "%s %s", prefix.c_str(), str.c_str());
                    break;
                case 2:
                    sprintf(param_name, "%s  %s", prefix.c_str(), str.c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->m_dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
    #ifdef MIDICTRL
        mydsp_poly* poly = dynamic_cast<mydsp_poly*>(obj->m_dsp);
        if (poly) {
            obj->m_midiHandler->removeMidiIn(poly);
        }
    #endif
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            obj->m_dsp = dsp_poly;
        #endif
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_midiHandler->addMidiIn(dsp_poly);
        obj->m_dsp->buildUserInterface(obj->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        obj->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(obj);
        
        // Send JSON to JS script
        faust_create_jsui(obj);
        
        systhread_mutex_unlock(obj->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* obj, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            obj->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            obj->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            obj->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, vector<t_object*> >::iterator it1;
    vector<t_object*>::iterator it2;
    for (it1 = x->m_output_table.begin(); it1 != x->m_output_table.end(); it1++) {
        FAUSTFLOAT value = x->m_dspUI->getOutputValue((*it1).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
                object_method_typed((*it2), gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 0) {
        post("polyphonic DSP voices = %d", nvoices);
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
    #else
        x->m_dsp = dsp_poly;
    #endif
        
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
    } else {
        post("monophonic DSP");
        x->m_dsp = new mydsp();
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    // Prepare JSON
    faust_make_json(x);
    
    int num_input;
    
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different

#ifdef SOUNDFILE
    Max_Meta3 meta3;
    x->m_dsp->metadata(&meta3);
    string bundle_path_str = SoundUI::getBinaryPathFrom(meta3.fName);
    if (bundle_path_str == "") {
        post("Bundle_path cannot be found!");
    }
    x->m_soundInterface = new SoundUI(bundle_path_str);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
#endif
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    x->m_dspUI->displayControls();
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher, so we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	delete x->m_dsp;
	delete x->m_dspUI;
	if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    // m_midiUI *must* be deleted before m_midiHandler
    delete x->m_midiUI;
    delete x->m_midiHandler;
#endif
#ifdef SOUNDFILE
    delete x->m_soundInterface;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(ins[0], sampleframes);
                x->m_dsp->compute(sampleframes, ++ins, outs);
            } else {
                x->m_dsp->compute(sampleframes, ins, outs);
            }
            faust_update_outputs(x);
        }
    #ifdef MIDICTRL
        GUI::updateAllGuis();
    #endif
        systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

    dsp* tmp_dsp = new mydsp();
    mspUI m_dspUI;
    tmp_dsp->buildUserInterface(&m_dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2018 Grame");
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/





#endif
