/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMH108_AE_7h7p_normal_6"
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
	FAUSTFLOAT fHslider1;
	double fRec2[2];
	double fRec1[3];
	FAUSTFLOAT fHslider2;
	double fRec3[2];
	double fRec4[3];
	double fRec5[3];
	double fRec6[3];
	double fRec7[3];
	double fRec8[3];
	double fRec9[3];
	double fRec10[3];
	double fRec11[3];
	double fRec12[3];
	double fRec13[3];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fRec32[2];
	double fRec30[2];
	double fRec29[2];
	double fRec27[2];
	double fRec26[2];
	double fRec24[2];
	double fRec23[2];
	double fRec21[2];
	double fConst12;
	double fConst13;
	double fRec20[2];
	double fRec18[2];
	double fRec17[2];
	double fRec15[2];
	double fRec14[3];
	double fRec51[2];
	double fRec49[2];
	double fRec48[2];
	double fRec46[2];
	double fRec45[2];
	double fRec43[2];
	double fRec42[2];
	double fRec40[2];
	double fRec39[2];
	double fRec37[2];
	double fRec36[2];
	double fRec34[2];
	double fRec33[3];
	double fRec70[2];
	double fRec68[2];
	double fRec67[2];
	double fRec65[2];
	double fRec64[2];
	double fRec62[2];
	double fRec61[2];
	double fRec59[2];
	double fRec58[2];
	double fRec56[2];
	double fRec55[2];
	double fRec53[2];
	double fRec52[3];
	double fRec89[2];
	double fRec87[2];
	double fRec86[2];
	double fRec84[2];
	double fRec83[2];
	double fRec81[2];
	double fRec80[2];
	double fRec78[2];
	double fRec77[2];
	double fRec75[2];
	double fRec74[2];
	double fRec72[2];
	double fRec71[3];
	double fRec108[2];
	double fRec106[2];
	double fRec105[2];
	double fRec103[2];
	double fRec102[2];
	double fRec100[2];
	double fRec99[2];
	double fRec97[2];
	double fRec96[2];
	double fRec94[2];
	double fRec93[2];
	double fRec91[2];
	double fRec90[3];
	double fRec127[2];
	double fRec125[2];
	double fRec124[2];
	double fRec122[2];
	double fRec121[2];
	double fRec119[2];
	double fRec118[2];
	double fRec116[2];
	double fRec115[2];
	double fRec113[2];
	double fRec112[2];
	double fRec110[2];
	double fRec109[3];
	double fRec146[2];
	double fRec144[2];
	double fRec143[2];
	double fRec141[2];
	double fRec140[2];
	double fRec138[2];
	double fRec137[2];
	double fRec135[2];
	double fRec134[2];
	double fRec132[2];
	double fRec131[2];
	double fRec129[2];
	double fRec128[3];
	double fRec147[3];
	double fRec148[3];
	double fConst14;
	double fConst15;
	double fConst16;
	double fRec152[2];
	double fRec150[2];
	double fRec149[3];
	double fRec156[2];
	double fRec154[2];
	double fRec153[3];
	double fRec160[2];
	double fRec158[2];
	double fRec157[3];
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fRec167[2];
	double fRec165[2];
	double fRec164[2];
	double fRec162[2];
	double fRec161[3];
	double fRec174[2];
	double fRec172[2];
	double fRec171[2];
	double fRec169[2];
	double fRec168[3];
	double fRec181[2];
	double fRec179[2];
	double fRec178[2];
	double fRec176[2];
	double fRec175[3];
	double fRec188[2];
	double fRec186[2];
	double fRec185[2];
	double fRec183[2];
	double fRec182[3];
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fRec198[2];
	double fRec196[2];
	double fRec195[2];
	double fRec193[2];
	double fRec192[2];
	double fRec190[2];
	double fRec189[3];
	double fRec208[2];
	double fRec206[2];
	double fRec205[2];
	double fRec203[2];
	double fRec202[2];
	double fRec200[2];
	double fRec199[3];
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fRec221[2];
	double fRec219[2];
	double fRec218[2];
	double fRec216[2];
	double fConst33;
	double fRec215[2];
	double fRec213[2];
	double fRec212[2];
	double fRec210[2];
	double fRec209[3];
	double fRec234[2];
	double fRec232[2];
	double fRec231[2];
	double fRec229[2];
	double fRec228[2];
	double fRec226[2];
	double fRec225[2];
	double fRec223[2];
	double fRec222[3];
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec250[2];
	double fRec248[2];
	double fRec247[2];
	double fRec245[2];
	double fConst41;
	double fRec244[2];
	double fRec242[2];
	double fRec241[2];
	double fRec239[2];
	double fConst42;
	double fRec238[2];
	double fRec236[2];
	double fRec235[3];
	double fRec266[2];
	double fRec264[2];
	double fRec263[2];
	double fRec261[2];
	double fRec260[2];
	double fRec258[2];
	double fRec257[2];
	double fRec255[2];
	double fRec254[2];
	double fRec252[2];
	double fRec251[3];
	double fRec282[2];
	double fRec280[2];
	double fRec279[2];
	double fRec277[2];
	double fRec276[2];
	double fRec274[2];
	double fRec273[2];
	double fRec271[2];
	double fRec270[2];
	double fRec268[2];
	double fRec267[3];
	double fRec298[2];
	double fRec296[2];
	double fRec295[2];
	double fRec293[2];
	double fRec292[2];
	double fRec290[2];
	double fRec289[2];
	double fRec287[2];
	double fRec286[2];
	double fRec284[2];
	double fRec283[3];
	double fRec317[2];
	double fRec315[2];
	double fRec314[2];
	double fRec312[2];
	double fRec311[2];
	double fRec309[2];
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fRec302[2];
	double fRec300[2];
	double fRec299[3];
	double fRec336[2];
	double fRec334[2];
	double fRec333[2];
	double fRec331[2];
	double fRec330[2];
	double fRec328[2];
	double fRec327[2];
	double fRec325[2];
	double fRec324[2];
	double fRec322[2];
	double fRec321[2];
	double fRec319[2];
	double fRec318[3];
	double fRec355[2];
	double fRec353[2];
	double fRec352[2];
	double fRec350[2];
	double fRec349[2];
	double fRec347[2];
	double fRec346[2];
	double fRec344[2];
	double fRec343[2];
	double fRec341[2];
	double fRec340[2];
	double fRec338[2];
	double fRec337[3];
	double fRec356[3];
	double fRec357[3];
	double fRec376[2];
	double fRec374[2];
	double fRec373[2];
	double fRec371[2];
	double fRec370[2];
	double fRec368[2];
	double fRec367[2];
	double fRec365[2];
	double fRec364[2];
	double fRec362[2];
	double fRec361[2];
	double fRec359[2];
	double fRec358[3];
	double fRec377[3];
	double fRec384[2];
	double fRec382[2];
	double fRec381[2];
	double fRec379[2];
	double fRec378[3];
	double fRec394[2];
	double fRec392[2];
	double fRec391[2];
	double fRec389[2];
	double fRec388[2];
	double fRec386[2];
	double fRec385[3];
	double fRec404[2];
	double fRec402[2];
	double fRec401[2];
	double fRec399[2];
	double fRec398[2];
	double fRec396[2];
	double fRec395[3];
	double fRec414[2];
	double fRec412[2];
	double fRec411[2];
	double fRec409[2];
	double fRec408[2];
	double fRec406[2];
	double fRec405[3];
	double fRec424[2];
	double fRec422[2];
	double fRec421[2];
	double fRec419[2];
	double fRec418[2];
	double fRec416[2];
	double fRec415[3];
	double fRec434[2];
	double fRec432[2];
	double fRec431[2];
	double fRec429[2];
	double fRec428[2];
	double fRec426[2];
	double fRec425[3];
	double fRec447[2];
	double fRec445[2];
	double fRec444[2];
	double fRec442[2];
	double fRec441[2];
	double fRec439[2];
	double fRec438[2];
	double fRec436[2];
	double fRec435[3];
	double fRec460[2];
	double fRec458[2];
	double fRec457[2];
	double fRec455[2];
	double fRec454[2];
	double fRec452[2];
	double fRec451[2];
	double fRec449[2];
	double fRec448[3];
	double fRec473[2];
	double fRec471[2];
	double fRec470[2];
	double fRec468[2];
	double fRec467[2];
	double fRec465[2];
	double fRec464[2];
	double fRec462[2];
	double fRec461[3];
	double fRec486[2];
	double fRec484[2];
	double fRec483[2];
	double fRec481[2];
	double fRec480[2];
	double fRec478[2];
	double fRec477[2];
	double fRec475[2];
	double fRec474[3];
	double fRec499[2];
	double fRec497[2];
	double fRec496[2];
	double fRec494[2];
	double fRec493[2];
	double fRec491[2];
	double fRec490[2];
	double fRec488[2];
	double fRec487[3];
	double fRec512[2];
	double fRec510[2];
	double fRec509[2];
	double fRec507[2];
	double fRec506[2];
	double fRec504[2];
	double fRec503[2];
	double fRec501[2];
	double fRec500[3];
	double fRec525[2];
	double fRec523[2];
	double fRec522[2];
	double fRec520[2];
	double fRec519[2];
	double fRec517[2];
	double fRec516[2];
	double fRec514[2];
	double fRec513[3];
	double fRec541[2];
	double fRec539[2];
	double fRec538[2];
	double fRec536[2];
	double fRec535[2];
	double fRec533[2];
	double fRec532[2];
	double fRec530[2];
	double fRec529[2];
	double fRec527[2];
	double fRec526[3];
	double fRec557[2];
	double fRec555[2];
	double fRec554[2];
	double fRec552[2];
	double fRec551[2];
	double fRec549[2];
	double fRec548[2];
	double fRec546[2];
	double fRec545[2];
	double fRec543[2];
	double fRec542[3];
	double fRec573[2];
	double fRec571[2];
	double fRec570[2];
	double fRec568[2];
	double fRec567[2];
	double fRec565[2];
	double fRec564[2];
	double fRec562[2];
	double fRec561[2];
	double fRec559[2];
	double fRec558[3];
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
	double fRec574[3];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec596[2];
	double fRec594[2];
	double fRec593[2];
	double fRec591[2];
	double fRec590[3];
	double fRec621[2];
	double fRec619[2];
	double fRec618[2];
	double fRec616[2];
	double fRec615[2];
	double fRec613[2];
	double fRec612[2];
	double fRec610[2];
	double fRec609[2];
	double fRec607[2];
	double fRec606[3];
	double fRec637[2];
	double fRec635[2];
	double fRec634[2];
	double fRec632[2];
	double fRec631[2];
	double fRec629[2];
	double fRec628[2];
	double fRec626[2];
	double fRec625[2];
	double fRec623[2];
	double fRec622[3];
	double fRec656[2];
	double fRec654[2];
	double fRec653[2];
	double fRec651[2];
	double fRec650[2];
	double fRec648[2];
	double fRec647[2];
	double fRec645[2];
	double fRec644[2];
	double fRec642[2];
	double fRec641[2];
	double fRec639[2];
	double fRec638[3];
	double fRec675[2];
	double fRec673[2];
	double fRec672[2];
	double fRec670[2];
	double fRec669[2];
	double fRec667[2];
	double fRec666[2];
	double fRec664[2];
	double fRec663[2];
	double fRec661[2];
	double fRec660[2];
	double fRec658[2];
	double fRec657[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMH108_AE_7h7p_normal_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMH108_AE_7h7p_normal_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 64;
		
	}
	virtual int getNumOutputs() {
		return 8;
		
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
			case 29: {
				rate = 1;
				break;
			}
			case 30: {
				rate = 1;
				break;
			}
			case 31: {
				rate = 1;
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
			case 36: {
				rate = 1;
				break;
			}
			case 37: {
				rate = 1;
				break;
			}
			case 38: {
				rate = 1;
				break;
			}
			case 39: {
				rate = 1;
				break;
			}
			case 40: {
				rate = 1;
				break;
			}
			case 41: {
				rate = 1;
				break;
			}
			case 42: {
				rate = 1;
				break;
			}
			case 43: {
				rate = 1;
				break;
			}
			case 44: {
				rate = 1;
				break;
			}
			case 45: {
				rate = 1;
				break;
			}
			case 46: {
				rate = 1;
				break;
			}
			case 47: {
				rate = 1;
				break;
			}
			case 48: {
				rate = 1;
				break;
			}
			case 49: {
				rate = 1;
				break;
			}
			case 50: {
				rate = 1;
				break;
			}
			case 51: {
				rate = 1;
				break;
			}
			case 52: {
				rate = 1;
				break;
			}
			case 53: {
				rate = 1;
				break;
			}
			case 54: {
				rate = 1;
				break;
			}
			case 55: {
				rate = 1;
				break;
			}
			case 56: {
				rate = 1;
				break;
			}
			case 57: {
				rate = 1;
				break;
			}
			case 58: {
				rate = 1;
				break;
			}
			case 59: {
				rate = 1;
				break;
			}
			case 60: {
				rate = 1;
				break;
			}
			case 61: {
				rate = 1;
				break;
			}
			case 62: {
				rate = 1;
				break;
			}
			case 63: {
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
		fConst1 = (3.1415926535897931 / double(iConst0));
		fConst2 = double(iConst0);
		fConst3 = mydsp_faustpower2_f(fConst2);
		fConst4 = ((((98255.397595587827 / fConst2) + 512.85989358739596) / fConst2) + 1.0);
		fConst5 = (0.0 - (393021.59038235131 / (fConst3 * fConst4)));
		fConst6 = (0.0 - (((393021.59038235131 / fConst2) + 1025.7197871747919) / (fConst2 * fConst4)));
		fConst7 = ((((88588.127641497427 / fConst2) + 583.23962682847252) / fConst2) + 1.0);
		fConst8 = ((((124930.13918924508 / fConst2) + 345.40189485091838) / fConst2) + 1.0);
		fConst9 = (1.0 / ((fConst7 * fConst4) * fConst8));
		fConst10 = (0.0 - (499720.55675698031 / (fConst3 * fConst8)));
		fConst11 = (0.0 - (((499720.55675698031 / fConst2) + 690.80378970183676) / (fConst2 * fConst8)));
		fConst12 = (0.0 - (((354352.51056598971 / fConst2) + 1166.479253656945) / (fConst2 * fConst7)));
		fConst13 = (0.0 - (354352.51056598971 / (fConst3 * fConst7)));
		fConst14 = ((68.64292453651359 / fConst2) + 1.0);
		fConst15 = (1.0 / fConst14);
		fConst16 = (0.0 - (137.28584907302718 / (fConst2 * fConst14)));
		fConst17 = ((((14135.553266776498 / fConst2) + 205.92877360954077) / fConst2) + 1.0);
		fConst18 = (1.0 / fConst17);
		fConst19 = (0.0 - (56542.213067105993 / (fConst3 * fConst17)));
		fConst20 = (0.0 - (((56542.213067105993 / fConst2) + 411.85754721908154) / (fConst2 * fConst17)));
		fConst21 = ((159.40159405739547 / fConst2) + 1.0);
		fConst22 = (0.0 - (318.80318811479094 / (fConst2 * fConst21)));
		fConst23 = ((((30435.884970630585 / fConst2) + 252.45595316168607) / fConst2) + 1.0);
		fConst24 = (1.0 / (fConst21 * fConst23));
		fConst25 = (0.0 - (121743.53988252234 / (fConst3 * fConst23)));
		fConst26 = (0.0 - (((121743.53988252234 / fConst2) + 504.91190632337214) / (fConst2 * fConst23)));
		fConst27 = ((((43066.935688277677 / fConst2) + 397.60873170249891) / fConst2) + 1.0);
		fConst28 = (0.0 - (172267.74275311071 / (fConst3 * fConst27)));
		fConst29 = ((((54128.805186304286 / fConst2) + 288.82051366263687) / fConst2) + 1.0);
		fConst30 = (1.0 / (fConst27 * fConst29));
		fConst31 = (0.0 - (216515.22074521714 / (fConst3 * fConst29)));
		fConst32 = (0.0 - (((216515.22074521714 / fConst2) + 577.64102732527374) / (fConst2 * fConst29)));
		fConst33 = (0.0 - (((172267.74275311071 / fConst2) + 795.21746340499783) / (fConst2 * fConst27)));
		fConst34 = ((((67249.802848164298 / fConst2) + 460.17618031355272) / fConst2) + 1.0);
		fConst35 = (0.0 - (268999.21139265719 / (fConst3 * fConst34)));
		fConst36 = ((250.3228022036094 / fConst2) + 1.0);
		fConst37 = ((((85549.854080565055 / fConst2) + 319.14488553054093) / fConst2) + 1.0);
		fConst38 = (1.0 / ((fConst36 * fConst34) * fConst37));
		fConst39 = (0.0 - (342199.41632226022 / (fConst3 * fConst37)));
		fConst40 = (0.0 - (((342199.41632226022 / fConst2) + 638.28977106108186) / (fConst2 * fConst37)));
		fConst41 = (0.0 - (((268999.21139265719 / fConst2) + 920.35236062710544) / (fConst2 * fConst34)));
		fConst42 = (0.0 - (500.6456044072188 / (fConst2 * fConst36)));
		
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
			fRec2[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec32[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec30[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec29[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec27[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec26[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec24[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec23[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec21[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec18[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec17[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec15[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec14[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec51[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec49[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec48[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec46[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec45[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec43[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec42[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec40[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec39[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec37[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec36[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec34[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec33[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec70[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec68[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec67[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec65[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec64[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec62[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec61[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec59[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec58[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec56[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec55[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec53[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec52[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec89[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec87[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec86[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec84[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec83[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec81[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec80[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec78[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec77[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec75[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec74[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec72[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 3); l65 = (l65 + 1)) {
			fRec71[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec108[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec106[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec105[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec103[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec102[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec100[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec99[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec97[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec96[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec94[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec93[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec91[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec90[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec127[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec125[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec124[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec122[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec121[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec119[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec118[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec116[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec115[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec113[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec112[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec110[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 3); l91 = (l91 + 1)) {
			fRec109[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec146[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec144[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec143[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec141[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec140[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec138[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec137[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec135[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec134[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec132[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec131[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec129[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 3); l104 = (l104 + 1)) {
			fRec128[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 3); l105 = (l105 + 1)) {
			fRec147[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 3); l106 = (l106 + 1)) {
			fRec148[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec152[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec150[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 3); l109 = (l109 + 1)) {
			fRec149[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec156[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec154[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 3); l112 = (l112 + 1)) {
			fRec153[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec160[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec158[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 3); l115 = (l115 + 1)) {
			fRec157[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec167[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec165[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec164[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec162[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 3); l120 = (l120 + 1)) {
			fRec161[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec174[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec172[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec171[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec169[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 3); l125 = (l125 + 1)) {
			fRec168[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec181[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec179[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec178[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec176[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 3); l130 = (l130 + 1)) {
			fRec175[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec188[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec186[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec185[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec183[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 3); l135 = (l135 + 1)) {
			fRec182[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec198[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec196[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec195[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec193[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec192[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec190[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 3); l142 = (l142 + 1)) {
			fRec189[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec208[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec206[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec205[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec203[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec202[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec200[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 3); l149 = (l149 + 1)) {
			fRec199[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec221[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec219[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec218[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec216[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec215[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec213[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec212[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec210[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 3); l158 = (l158 + 1)) {
			fRec209[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec234[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec232[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec231[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec229[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec228[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec226[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec225[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec223[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 3); l167 = (l167 + 1)) {
			fRec222[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec250[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec248[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec247[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec245[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec244[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec242[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec241[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec239[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec238[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec236[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 3); l178 = (l178 + 1)) {
			fRec235[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec266[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec264[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec263[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec261[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec260[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec258[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec257[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec255[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec254[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec252[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 3); l189 = (l189 + 1)) {
			fRec251[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec282[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec280[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec279[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec277[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec276[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec274[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec273[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec271[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec270[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec268[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 3); l200 = (l200 + 1)) {
			fRec267[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec298[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec296[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec295[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec293[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec292[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec290[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec289[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec287[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec286[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec284[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 3); l211 = (l211 + 1)) {
			fRec283[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec317[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec315[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec314[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec312[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec311[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec309[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec308[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec306[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec305[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec303[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec302[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec300[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 3); l224 = (l224 + 1)) {
			fRec299[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec336[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec334[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec333[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec331[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec330[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec328[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec327[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec325[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec324[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec322[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec321[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec319[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 3); l237 = (l237 + 1)) {
			fRec318[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec355[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec353[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec352[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec350[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec349[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec347[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec346[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec344[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec343[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec341[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec340[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec338[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 3); l250 = (l250 + 1)) {
			fRec337[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 3); l251 = (l251 + 1)) {
			fRec356[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 3); l252 = (l252 + 1)) {
			fRec357[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec376[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec374[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec373[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec371[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec370[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec368[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec367[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec365[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec364[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec362[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec361[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec359[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 3); l265 = (l265 + 1)) {
			fRec358[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 3); l266 = (l266 + 1)) {
			fRec377[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec384[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec382[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec381[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec379[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 3); l271 = (l271 + 1)) {
			fRec378[l271] = 0.0;
			
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
		for (int l278 = 0; (l278 < 3); l278 = (l278 + 1)) {
			fRec385[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec404[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec402[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec401[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec399[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec398[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec396[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 3); l285 = (l285 + 1)) {
			fRec395[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec414[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec412[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec411[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec409[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec408[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec406[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 3); l292 = (l292 + 1)) {
			fRec405[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec424[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec422[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec421[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec419[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec418[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec416[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 3); l299 = (l299 + 1)) {
			fRec415[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec434[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec432[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec431[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec429[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec428[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec426[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 3); l306 = (l306 + 1)) {
			fRec425[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec447[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec445[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec444[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec442[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec441[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec439[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec438[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec436[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 3); l315 = (l315 + 1)) {
			fRec435[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec460[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec458[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec457[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec455[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec454[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec452[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec451[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec449[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 3); l324 = (l324 + 1)) {
			fRec448[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec473[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec471[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec470[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec468[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec467[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec465[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec464[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec462[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 3); l333 = (l333 + 1)) {
			fRec461[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec486[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec484[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec483[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec481[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec480[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec478[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec477[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec475[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 3); l342 = (l342 + 1)) {
			fRec474[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec499[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec497[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec496[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec494[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec493[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec491[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec490[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec488[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 3); l351 = (l351 + 1)) {
			fRec487[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec512[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec510[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec509[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec507[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec506[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec504[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec503[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec501[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 3); l360 = (l360 + 1)) {
			fRec500[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec525[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec523[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec522[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec520[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec519[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec517[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec516[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec514[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 3); l369 = (l369 + 1)) {
			fRec513[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec541[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec539[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec538[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec536[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec535[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec533[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec532[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec530[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec529[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec527[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 3); l380 = (l380 + 1)) {
			fRec526[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec557[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec555[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec554[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec552[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec551[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec549[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec548[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec546[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec545[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec543[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 3); l391 = (l391 + 1)) {
			fRec542[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec573[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec571[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec570[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec568[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec567[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec565[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec564[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec562[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec561[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec559[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 3); l402 = (l402 + 1)) {
			fRec558[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec589[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec587[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec586[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec584[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec583[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec581[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec580[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec578[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec577[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec575[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 3); l413 = (l413 + 1)) {
			fRec574[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec605[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec603[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec602[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec600[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec599[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec597[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec596[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec594[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec593[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec591[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 3); l424 = (l424 + 1)) {
			fRec590[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec621[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec619[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec618[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec616[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec615[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec613[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec612[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec610[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec609[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec607[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 3); l435 = (l435 + 1)) {
			fRec606[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec637[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec635[l437] = 0.0;
			
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
		for (int l446 = 0; (l446 < 3); l446 = (l446 + 1)) {
			fRec622[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec656[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec654[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec653[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec651[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec650[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec648[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec647[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec645[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec644[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec642[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec641[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec639[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 3); l459 = (l459 + 1)) {
			fRec638[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec675[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec673[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec672[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec670[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec669[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec667[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec666[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec664[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec663[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec661[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec660[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec658[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 3); l472 = (l472 + 1)) {
			fRec657[l472] = 0.0;
			
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
		ui_interface->openVerticalBox("KMH108_AE_7h7p_normal_6");
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
		FAUSTFLOAT* input36 = inputs[36];
		FAUSTFLOAT* input37 = inputs[37];
		FAUSTFLOAT* input38 = inputs[38];
		FAUSTFLOAT* input39 = inputs[39];
		FAUSTFLOAT* input40 = inputs[40];
		FAUSTFLOAT* input41 = inputs[41];
		FAUSTFLOAT* input42 = inputs[42];
		FAUSTFLOAT* input43 = inputs[43];
		FAUSTFLOAT* input44 = inputs[44];
		FAUSTFLOAT* input45 = inputs[45];
		FAUSTFLOAT* input46 = inputs[46];
		FAUSTFLOAT* input47 = inputs[47];
		FAUSTFLOAT* input48 = inputs[48];
		FAUSTFLOAT* input49 = inputs[49];
		FAUSTFLOAT* input50 = inputs[50];
		FAUSTFLOAT* input51 = inputs[51];
		FAUSTFLOAT* input52 = inputs[52];
		FAUSTFLOAT* input53 = inputs[53];
		FAUSTFLOAT* input54 = inputs[54];
		FAUSTFLOAT* input55 = inputs[55];
		FAUSTFLOAT* input56 = inputs[56];
		FAUSTFLOAT* input57 = inputs[57];
		FAUSTFLOAT* input58 = inputs[58];
		FAUSTFLOAT* input59 = inputs[59];
		FAUSTFLOAT* input60 = inputs[60];
		FAUSTFLOAT* input61 = inputs[61];
		FAUSTFLOAT* input62 = inputs[62];
		FAUSTFLOAT* input63 = inputs[63];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		double fSlow0 = (0.0010000000000000009 * (double((double(fCheckbox0) < 0.5)) * std::pow(10.0, (0.050000000000000003 * double(fHslider0)))));
		double fSlow1 = (0.0010000000000000009 * double(fHslider1));
		double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider2))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
			fRec2[0] = (fSlow1 + (0.999 * fRec2[1]));
			double fTemp0 = std::tan((fConst1 * fRec2[0]));
			double fTemp1 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp2 = mydsp_faustpower2_f(fTemp0);
			double fTemp3 = (fTemp2 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec1[0] = (double(input63[i]) - (((fRec1[2] * fTemp1) + (2.0 * (fRec1[1] * fTemp3))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = ((((fRec1[2] + (fRec1[0] + (2.0 * fRec1[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec1[1] * fTemp6) + ((fRec1[0] + fRec1[2]) / fTemp4))))));
			fRec4[0] = (double(input62[i]) - (((fRec4[2] * fTemp1) + (2.0 * (fRec4[1] * fTemp3))) / fTemp4));
			double fTemp8 = ((((fRec4[2] + (fRec4[0] + (2.0 * fRec4[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec4[1] * fTemp6) + ((fRec4[0] + fRec4[2]) / fTemp4))))));
			fRec5[0] = (double(input60[i]) - (((fRec5[2] * fTemp1) + (2.0 * (fRec5[1] * fTemp3))) / fTemp4));
			double fTemp9 = ((((fRec5[2] + (fRec5[0] + (2.0 * fRec5[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec5[1] * fTemp6) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			fRec6[0] = (double(input59[i]) - (((fRec6[2] * fTemp1) + (2.0 * (fRec6[1] * fTemp3))) / fTemp4));
			double fTemp10 = ((((fRec6[2] + (fRec6[0] + (2.0 * fRec6[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec6[1] * fTemp6) + ((fRec6[0] + fRec6[2]) / fTemp4))))));
			fRec7[0] = (double(input57[i]) - (((fRec7[2] * fTemp1) + (2.0 * (fRec7[1] * fTemp3))) / fTemp4));
			double fTemp11 = ((((fRec7[2] + (fRec7[0] + (2.0 * fRec7[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec7[1] * fTemp6) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			fRec8[0] = (double(input56[i]) - (((fRec8[2] * fTemp1) + (2.0 * (fRec8[1] * fTemp3))) / fTemp4));
			double fTemp12 = ((((fRec8[2] + (fRec8[0] + (2.0 * fRec8[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec8[1] * fTemp6) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			fRec9[0] = (double(input55[i]) - (((fRec9[2] * fTemp1) + (2.0 * (fRec9[1] * fTemp3))) / fTemp4));
			double fTemp13 = ((((fRec9[2] + (fRec9[0] + (2.0 * fRec9[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec9[1] * fTemp6) + ((fRec9[0] + fRec9[2]) / fTemp4))))));
			fRec10[0] = (double(input54[i]) - (((fRec10[2] * fTemp1) + (2.0 * (fRec10[1] * fTemp3))) / fTemp4));
			double fTemp14 = ((((fRec10[2] + (fRec10[0] + (2.0 * fRec10[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec10[1] * fTemp6) + ((fRec10[0] + fRec10[2]) / fTemp4))))));
			fRec11[0] = (double(input53[i]) - (((fRec11[2] * fTemp1) + (2.0 * (fRec11[1] * fTemp3))) / fTemp4));
			double fTemp15 = ((((fRec11[2] + (fRec11[0] + (2.0 * fRec11[1]))) * fTemp2) / fTemp5) + (0.1550188129 * ((0.0 - ((fRec11[1] * fTemp6) + ((fRec11[0] + fRec11[2]) / fTemp4))) * fRec3[0])));
			fRec12[0] = (double(input52[i]) - (((fRec12[2] * fTemp1) + (2.0 * (fRec12[1] * fTemp3))) / fTemp4));
			double fTemp16 = ((((fRec12[2] + (fRec12[0] + (2.0 * fRec12[1]))) * fTemp2) / fTemp5) + (0.1550188129 * ((0.0 - ((fRec12[1] * fTemp6) + ((fRec12[0] + fRec12[2]) / fTemp4))) * fRec3[0])));
			fRec13[0] = (double(input51[i]) - (((fRec13[2] * fTemp1) + (2.0 * (fRec13[1] * fTemp3))) / fTemp4));
			double fTemp17 = ((((fRec13[2] + (fRec13[0] + (2.0 * fRec13[1]))) * fTemp2) / fTemp5) + (0.1550188129 * ((0.0 - ((fRec13[1] * fTemp6) + ((fRec13[0] + fRec13[2]) / fTemp4))) * fRec3[0])));
			double fTemp18 = (fConst5 * fRec21[1]);
			double fTemp19 = (fConst6 * fRec24[1]);
			double fTemp20 = (fConst9 * double(input41[i]));
			double fTemp21 = (fConst10 * fRec27[1]);
			double fTemp22 = (fConst11 * fRec30[1]);
			fRec32[0] = (fTemp20 + (fTemp21 + (fRec32[1] + fTemp22)));
			fRec30[0] = fRec32[0];
			double fRec31 = ((fTemp22 + fTemp21) + fTemp20);
			fRec29[0] = (fRec30[0] + fRec29[1]);
			fRec27[0] = fRec29[0];
			double fRec28 = fRec31;
			fRec26[0] = (fTemp18 + (fTemp19 + (fRec28 + fRec26[1])));
			fRec24[0] = fRec26[0];
			double fRec25 = (fTemp18 + (fRec28 + fTemp19));
			fRec23[0] = (fRec24[0] + fRec23[1]);
			fRec21[0] = fRec23[0];
			double fRec22 = fRec25;
			double fTemp23 = (fConst12 * fRec18[1]);
			double fTemp24 = (fConst13 * fRec15[1]);
			fRec20[0] = (((fRec22 + fRec20[1]) + fTemp23) + fTemp24);
			fRec18[0] = fRec20[0];
			double fRec19 = ((fRec22 + fTemp23) + fTemp24);
			fRec17[0] = (fRec18[0] + fRec17[1]);
			fRec15[0] = fRec17[0];
			double fRec16 = fRec19;
			fRec14[0] = (fRec16 - (((fRec14[2] * fTemp1) + (2.0 * (fRec14[1] * fTemp3))) / fTemp4));
			double fTemp25 = ((((fRec14[2] + (fRec14[0] + (2.0 * fRec14[1]))) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec14[1] * fTemp6) + ((fRec14[0] + fRec14[2]) / fTemp4))) * fRec3[0])));
			double fTemp26 = (fConst13 * fRec34[1]);
			double fTemp27 = (fConst12 * fRec37[1]);
			double fTemp28 = (fConst5 * fRec40[1]);
			double fTemp29 = (fConst6 * fRec43[1]);
			double fTemp30 = (fConst9 * double(input42[i]));
			double fTemp31 = (fConst10 * fRec46[1]);
			double fTemp32 = (fConst11 * fRec49[1]);
			fRec51[0] = (fTemp30 + (fTemp31 + (fRec51[1] + fTemp32)));
			fRec49[0] = fRec51[0];
			double fRec50 = ((fTemp32 + fTemp31) + fTemp30);
			fRec48[0] = (fRec49[0] + fRec48[1]);
			fRec46[0] = fRec48[0];
			double fRec47 = fRec50;
			fRec45[0] = (fTemp28 + (fTemp29 + (fRec47 + fRec45[1])));
			fRec43[0] = fRec45[0];
			double fRec44 = (fTemp28 + (fRec47 + fTemp29));
			fRec42[0] = (fRec43[0] + fRec42[1]);
			fRec40[0] = fRec42[0];
			double fRec41 = fRec44;
			fRec39[0] = (fTemp26 + (fTemp27 + (fRec41 + fRec39[1])));
			fRec37[0] = fRec39[0];
			double fRec38 = (fTemp26 + (fRec41 + fTemp27));
			fRec36[0] = (fRec37[0] + fRec36[1]);
			fRec34[0] = fRec36[0];
			double fRec35 = fRec38;
			fRec33[0] = (fRec35 - (((fRec33[2] * fTemp1) + (2.0 * (fRec33[1] * fTemp3))) / fTemp4));
			double fTemp33 = ((((fRec33[2] + (fRec33[0] + (2.0 * fRec33[1]))) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec33[1] * fTemp6) + ((fRec33[0] + fRec33[2]) / fTemp4))) * fRec3[0])));
			double fTemp34 = (fConst13 * fRec53[1]);
			double fTemp35 = (fConst12 * fRec56[1]);
			double fTemp36 = (fConst5 * fRec59[1]);
			double fTemp37 = (fConst6 * fRec62[1]);
			double fTemp38 = (fConst9 * double(input43[i]));
			double fTemp39 = (fConst10 * fRec65[1]);
			double fTemp40 = (fConst11 * fRec68[1]);
			fRec70[0] = (fTemp38 + (fTemp39 + (fRec70[1] + fTemp40)));
			fRec68[0] = fRec70[0];
			double fRec69 = ((fTemp40 + fTemp39) + fTemp38);
			fRec67[0] = (fRec68[0] + fRec67[1]);
			fRec65[0] = fRec67[0];
			double fRec66 = fRec69;
			fRec64[0] = (fTemp36 + (fTemp37 + (fRec66 + fRec64[1])));
			fRec62[0] = fRec64[0];
			double fRec63 = (fTemp36 + (fRec66 + fTemp37));
			fRec61[0] = (fRec62[0] + fRec61[1]);
			fRec59[0] = fRec61[0];
			double fRec60 = fRec63;
			fRec58[0] = (fTemp34 + (fTemp35 + (fRec60 + fRec58[1])));
			fRec56[0] = fRec58[0];
			double fRec57 = (fTemp34 + (fRec60 + fTemp35));
			fRec55[0] = (fRec56[0] + fRec55[1]);
			fRec53[0] = fRec55[0];
			double fRec54 = fRec57;
			fRec52[0] = (fRec54 - (((fRec52[2] * fTemp1) + (2.0 * (fRec52[1] * fTemp3))) / fTemp4));
			double fTemp41 = ((((fRec52[2] + (fRec52[0] + (2.0 * fRec52[1]))) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec52[1] * fTemp6) + ((fRec52[0] + fRec52[2]) / fTemp4))) * fRec3[0])));
			double fTemp42 = (fConst13 * fRec72[1]);
			double fTemp43 = (fConst12 * fRec75[1]);
			double fTemp44 = (fConst5 * fRec78[1]);
			double fTemp45 = (fConst6 * fRec81[1]);
			double fTemp46 = (fConst9 * double(input44[i]));
			double fTemp47 = (fConst10 * fRec84[1]);
			double fTemp48 = (fConst11 * fRec87[1]);
			fRec89[0] = (fTemp46 + (fTemp47 + (fRec89[1] + fTemp48)));
			fRec87[0] = fRec89[0];
			double fRec88 = ((fTemp48 + fTemp47) + fTemp46);
			fRec86[0] = (fRec86[1] + fRec87[0]);
			fRec84[0] = fRec86[0];
			double fRec85 = fRec88;
			fRec83[0] = ((fTemp44 + (fRec83[1] + fTemp45)) + fRec85);
			fRec81[0] = fRec83[0];
			double fRec82 = ((fTemp45 + fTemp44) + fRec85);
			fRec80[0] = (fRec80[1] + fRec81[0]);
			fRec78[0] = fRec80[0];
			double fRec79 = fRec82;
			fRec77[0] = ((fTemp42 + (fRec77[1] + fTemp43)) + fRec79);
			fRec75[0] = fRec77[0];
			double fRec76 = ((fTemp43 + fTemp42) + fRec79);
			fRec74[0] = (fRec74[1] + fRec75[0]);
			fRec72[0] = fRec74[0];
			double fRec73 = fRec76;
			fRec71[0] = (fRec73 - (((fRec71[2] * fTemp1) + (2.0 * (fRec71[1] * fTemp3))) / fTemp4));
			double fTemp49 = ((((fRec71[2] + ((2.0 * fRec71[1]) + fRec71[0])) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec71[1] * fTemp6) + ((fRec71[2] + fRec71[0]) / fTemp4))) * fRec3[0])));
			double fTemp50 = (fConst13 * fRec91[1]);
			double fTemp51 = (fConst12 * fRec94[1]);
			double fTemp52 = (fConst5 * fRec97[1]);
			double fTemp53 = (fConst6 * fRec100[1]);
			double fTemp54 = (fConst9 * double(input45[i]));
			double fTemp55 = (fConst10 * fRec103[1]);
			double fTemp56 = (fConst11 * fRec106[1]);
			fRec108[0] = (fTemp54 + (fTemp55 + (fRec108[1] + fTemp56)));
			fRec106[0] = fRec108[0];
			double fRec107 = ((fTemp56 + fTemp55) + fTemp54);
			fRec105[0] = (fRec105[1] + fRec106[0]);
			fRec103[0] = fRec105[0];
			double fRec104 = fRec107;
			fRec102[0] = ((fTemp52 + (fRec102[1] + fTemp53)) + fRec104);
			fRec100[0] = fRec102[0];
			double fRec101 = ((fTemp53 + fTemp52) + fRec104);
			fRec99[0] = (fRec99[1] + fRec100[0]);
			fRec97[0] = fRec99[0];
			double fRec98 = fRec101;
			fRec96[0] = ((fTemp50 + (fRec96[1] + fTemp51)) + fRec98);
			fRec94[0] = fRec96[0];
			double fRec95 = ((fTemp51 + fTemp50) + fRec98);
			fRec93[0] = (fRec93[1] + fRec94[0]);
			fRec91[0] = fRec93[0];
			double fRec92 = fRec95;
			fRec90[0] = (fRec92 - (((fRec90[2] * fTemp1) + (2.0 * (fRec90[1] * fTemp3))) / fTemp4));
			double fTemp57 = ((((fRec90[2] + ((2.0 * fRec90[1]) + fRec90[0])) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec90[1] * fTemp6) + ((fRec90[2] + fRec90[0]) / fTemp4))) * fRec3[0])));
			double fTemp58 = (fConst13 * fRec110[1]);
			double fTemp59 = (fConst12 * fRec113[1]);
			double fTemp60 = (fConst5 * fRec116[1]);
			double fTemp61 = (fConst6 * fRec119[1]);
			double fTemp62 = (fConst9 * double(input46[i]));
			double fTemp63 = (fConst10 * fRec122[1]);
			double fTemp64 = (fConst11 * fRec125[1]);
			fRec127[0] = (fTemp62 + (fTemp63 + (fRec127[1] + fTemp64)));
			fRec125[0] = fRec127[0];
			double fRec126 = ((fTemp64 + fTemp63) + fTemp62);
			fRec124[0] = (fRec124[1] + fRec125[0]);
			fRec122[0] = fRec124[0];
			double fRec123 = fRec126;
			fRec121[0] = ((fTemp60 + (fRec121[1] + fTemp61)) + fRec123);
			fRec119[0] = fRec121[0];
			double fRec120 = ((fTemp61 + fTemp60) + fRec123);
			fRec118[0] = (fRec118[1] + fRec119[0]);
			fRec116[0] = fRec118[0];
			double fRec117 = fRec120;
			fRec115[0] = ((fTemp58 + (fRec115[1] + fTemp59)) + fRec117);
			fRec113[0] = fRec115[0];
			double fRec114 = ((fTemp59 + fTemp58) + fRec117);
			fRec112[0] = (fRec112[1] + fRec113[0]);
			fRec110[0] = fRec112[0];
			double fRec111 = fRec114;
			fRec109[0] = (fRec111 - (((fRec109[2] * fTemp1) + (2.0 * (fRec109[1] * fTemp3))) / fTemp4));
			double fTemp65 = ((((fRec109[2] + ((2.0 * fRec109[1]) + fRec109[0])) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec109[1] * fTemp6) + ((fRec109[2] + fRec109[0]) / fTemp4))) * fRec3[0])));
			double fTemp66 = (fConst13 * fRec129[1]);
			double fTemp67 = (fConst12 * fRec132[1]);
			double fTemp68 = (fConst5 * fRec135[1]);
			double fTemp69 = (fConst6 * fRec138[1]);
			double fTemp70 = (fConst9 * double(input47[i]));
			double fTemp71 = (fConst10 * fRec141[1]);
			double fTemp72 = (fConst11 * fRec144[1]);
			fRec146[0] = (fTemp70 + (fTemp71 + (fRec146[1] + fTemp72)));
			fRec144[0] = fRec146[0];
			double fRec145 = ((fTemp72 + fTemp71) + fTemp70);
			fRec143[0] = (fRec143[1] + fRec144[0]);
			fRec141[0] = fRec143[0];
			double fRec142 = fRec145;
			fRec140[0] = ((fTemp68 + (fRec140[1] + fTemp69)) + fRec142);
			fRec138[0] = fRec140[0];
			double fRec139 = ((fTemp69 + fTemp68) + fRec142);
			fRec137[0] = (fRec137[1] + fRec138[0]);
			fRec135[0] = fRec137[0];
			double fRec136 = fRec139;
			fRec134[0] = ((fTemp66 + (fRec134[1] + fTemp67)) + fRec136);
			fRec132[0] = fRec134[0];
			double fRec133 = ((fTemp67 + fTemp66) + fRec136);
			fRec131[0] = (fRec131[1] + fRec132[0]);
			fRec129[0] = fRec131[0];
			double fRec130 = fRec133;
			fRec128[0] = (fRec130 - (((fRec128[2] * fTemp1) + (2.0 * (fRec128[1] * fTemp3))) / fTemp4));
			double fTemp73 = ((((fRec128[2] + ((2.0 * fRec128[1]) + fRec128[0])) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec128[1] * fTemp6) + ((fRec128[2] + fRec128[0]) / fTemp4))) * fRec3[0])));
			fRec147[0] = (double(input50[i]) - (((fRec147[2] * fTemp1) + (2.0 * (fRec147[1] * fTemp3))) / fTemp4));
			double fTemp74 = ((((fRec147[2] + (fRec147[0] + (2.0 * fRec147[1]))) * fTemp2) / fTemp5) + (0.1550188129 * ((0.0 - ((fRec147[1] * fTemp6) + ((fRec147[0] + fRec147[2]) / fTemp4))) * fRec3[0])));
			fRec148[0] = (double(input0[i]) - (((fRec148[2] * fTemp1) + (2.0 * (fRec148[1] * fTemp3))) / fTemp4));
			double fTemp75 = (((fTemp2 * (fRec148[2] + (fRec148[0] + (2.0 * fRec148[1])))) / fTemp5) + (fRec3[0] * (0.0 - ((fRec148[1] * fTemp6) + ((fRec148[0] + fRec148[2]) / fTemp4)))));
			double fTemp76 = (fConst15 * double(input1[i]));
			double fTemp77 = (fConst16 * fRec150[1]);
			fRec152[0] = (fTemp76 + (fRec152[1] + fTemp77));
			fRec150[0] = fRec152[0];
			double fRec151 = (fTemp77 + fTemp76);
			fRec149[0] = (fRec151 - (((fTemp1 * fRec149[2]) + (2.0 * (fTemp3 * fRec149[1]))) / fTemp4));
			double fTemp78 = (((fTemp2 * (fRec149[2] + (fRec149[0] + (2.0 * fRec149[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec149[1]) + ((fRec149[0] + fRec149[2]) / fTemp4))))));
			double fTemp79 = (fConst15 * double(input2[i]));
			double fTemp80 = (fConst16 * fRec154[1]);
			fRec156[0] = (fTemp79 + (fRec156[1] + fTemp80));
			fRec154[0] = fRec156[0];
			double fRec155 = (fTemp80 + fTemp79);
			fRec153[0] = (fRec155 - (((fTemp1 * fRec153[2]) + (2.0 * (fTemp3 * fRec153[1]))) / fTemp4));
			double fTemp81 = (((fTemp2 * (fRec153[2] + (fRec153[0] + (2.0 * fRec153[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec153[1]) + ((fRec153[0] + fRec153[2]) / fTemp4))))));
			double fTemp82 = (fConst15 * double(input3[i]));
			double fTemp83 = (fConst16 * fRec158[1]);
			fRec160[0] = (fTemp82 + (fRec160[1] + fTemp83));
			fRec158[0] = fRec160[0];
			double fRec159 = (fTemp83 + fTemp82);
			fRec157[0] = (fRec159 - (((fTemp1 * fRec157[2]) + (2.0 * (fTemp3 * fRec157[1]))) / fTemp4));
			double fTemp84 = (((fTemp2 * (fRec157[2] + (fRec157[0] + (2.0 * fRec157[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec157[1]) + ((fRec157[0] + fRec157[2]) / fTemp4))))));
			double fTemp85 = (fConst18 * double(input4[i]));
			double fTemp86 = (fConst19 * fRec162[1]);
			double fTemp87 = (fConst20 * fRec165[1]);
			fRec167[0] = (fTemp85 + (fTemp86 + (fRec167[1] + fTemp87)));
			fRec165[0] = fRec167[0];
			double fRec166 = ((fTemp87 + fTemp86) + fTemp85);
			fRec164[0] = (fRec165[0] + fRec164[1]);
			fRec162[0] = fRec164[0];
			double fRec163 = fRec166;
			fRec161[0] = (fRec163 - (((fTemp1 * fRec161[2]) + (2.0 * (fTemp3 * fRec161[1]))) / fTemp4));
			double fTemp88 = (((fTemp2 * (fRec161[2] + (fRec161[0] + (2.0 * fRec161[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec161[1]) + ((fRec161[0] + fRec161[2]) / fTemp4))))));
			double fTemp89 = (fConst18 * double(input5[i]));
			double fTemp90 = (fConst19 * fRec169[1]);
			double fTemp91 = (fConst20 * fRec172[1]);
			fRec174[0] = (fTemp89 + (fTemp90 + (fRec174[1] + fTemp91)));
			fRec172[0] = fRec174[0];
			double fRec173 = ((fTemp91 + fTemp90) + fTemp89);
			fRec171[0] = (fRec172[0] + fRec171[1]);
			fRec169[0] = fRec171[0];
			double fRec170 = fRec173;
			fRec168[0] = (fRec170 - (((fTemp1 * fRec168[2]) + (2.0 * (fTemp3 * fRec168[1]))) / fTemp4));
			double fTemp92 = (((fTemp2 * (fRec168[2] + (fRec168[0] + (2.0 * fRec168[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec168[1]) + ((fRec168[0] + fRec168[2]) / fTemp4))))));
			double fTemp93 = (fConst18 * double(input6[i]));
			double fTemp94 = (fConst19 * fRec176[1]);
			double fTemp95 = (fConst20 * fRec179[1]);
			fRec181[0] = (fTemp93 + (fTemp94 + (fRec181[1] + fTemp95)));
			fRec179[0] = fRec181[0];
			double fRec180 = ((fTemp95 + fTemp94) + fTemp93);
			fRec178[0] = (fRec179[0] + fRec178[1]);
			fRec176[0] = fRec178[0];
			double fRec177 = fRec180;
			fRec175[0] = (fRec177 - (((fTemp1 * fRec175[2]) + (2.0 * (fTemp3 * fRec175[1]))) / fTemp4));
			double fTemp96 = (((fTemp2 * (fRec175[2] + (fRec175[0] + (2.0 * fRec175[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec175[1]) + ((fRec175[0] + fRec175[2]) / fTemp4))))));
			double fTemp97 = (fConst18 * double(input8[i]));
			double fTemp98 = (fConst19 * fRec183[1]);
			double fTemp99 = (fConst20 * fRec186[1]);
			fRec188[0] = (fTemp97 + (fTemp98 + (fRec188[1] + fTemp99)));
			fRec186[0] = fRec188[0];
			double fRec187 = ((fTemp99 + fTemp98) + fTemp97);
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			double fRec184 = fRec187;
			fRec182[0] = (fRec184 - (((fTemp1 * fRec182[2]) + (2.0 * (fTemp3 * fRec182[1]))) / fTemp4));
			double fTemp100 = (((fTemp2 * (fRec182[2] + (fRec182[0] + (2.0 * fRec182[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec182[1]) + ((fRec182[0] + fRec182[2]) / fTemp4))))));
			double fTemp101 = (fConst22 * fRec190[1]);
			double fTemp102 = (fConst24 * double(input9[i]));
			double fTemp103 = (fConst25 * fRec193[1]);
			double fTemp104 = (fConst26 * fRec196[1]);
			fRec198[0] = (fTemp102 + (fTemp103 + (fRec198[1] + fTemp104)));
			fRec196[0] = fRec198[0];
			double fRec197 = ((fTemp104 + fTemp103) + fTemp102);
			fRec195[0] = (fRec196[0] + fRec195[1]);
			fRec193[0] = fRec195[0];
			double fRec194 = fRec197;
			fRec192[0] = (fTemp101 + (fRec194 + fRec192[1]));
			fRec190[0] = fRec192[0];
			double fRec191 = (fRec194 + fTemp101);
			fRec189[0] = (fRec191 - (((fTemp1 * fRec189[2]) + (2.0 * (fTemp3 * fRec189[1]))) / fTemp4));
			double fTemp105 = (((fTemp2 * (fRec189[2] + (fRec189[0] + (2.0 * fRec189[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec189[1]) + ((fRec189[0] + fRec189[2]) / fTemp4))))));
			double fTemp106 = (fConst22 * fRec200[1]);
			double fTemp107 = (fConst24 * double(input15[i]));
			double fTemp108 = (fConst25 * fRec203[1]);
			double fTemp109 = (fConst26 * fRec206[1]);
			fRec208[0] = (fTemp107 + (fTemp108 + (fRec208[1] + fTemp109)));
			fRec206[0] = fRec208[0];
			double fRec207 = ((fTemp109 + fTemp108) + fTemp107);
			fRec205[0] = (fRec206[0] + fRec205[1]);
			fRec203[0] = fRec205[0];
			double fRec204 = fRec207;
			fRec202[0] = (fTemp106 + (fRec204 + fRec202[1]));
			fRec200[0] = fRec202[0];
			double fRec201 = (fRec204 + fTemp106);
			fRec199[0] = (fRec201 - (((fTemp1 * fRec199[2]) + (2.0 * (fTemp3 * fRec199[1]))) / fTemp4));
			double fTemp110 = (((fTemp2 * (fRec199[2] + (fRec199[0] + (2.0 * fRec199[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec199[1]) + ((fRec199[0] + fRec199[2]) / fTemp4))))));
			double fTemp111 = (fConst28 * fRec210[1]);
			double fTemp112 = (fConst30 * double(input16[i]));
			double fTemp113 = (fConst31 * fRec216[1]);
			double fTemp114 = (fConst32 * fRec219[1]);
			fRec221[0] = (fTemp112 + (fTemp113 + (fRec221[1] + fTemp114)));
			fRec219[0] = fRec221[0];
			double fRec220 = ((fTemp114 + fTemp113) + fTemp112);
			fRec218[0] = (fRec219[0] + fRec218[1]);
			fRec216[0] = fRec218[0];
			double fRec217 = fRec220;
			double fTemp115 = (fRec217 + (fConst33 * fRec213[1]));
			fRec215[0] = (fTemp111 + (fRec215[1] + fTemp115));
			fRec213[0] = fRec215[0];
			double fRec214 = (fTemp111 + fTemp115);
			fRec212[0] = (fRec213[0] + fRec212[1]);
			fRec210[0] = fRec212[0];
			double fRec211 = fRec214;
			fRec209[0] = (fRec211 - (((fTemp1 * fRec209[2]) + (2.0 * (fTemp3 * fRec209[1]))) / fTemp4));
			double fTemp116 = (((fTemp2 * (fRec209[2] + (fRec209[0] + (2.0 * fRec209[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec209[1]) + ((fRec209[0] + fRec209[2]) / fTemp4))))));
			double fTemp117 = (fConst28 * fRec223[1]);
			double fTemp118 = (fConst33 * fRec226[1]);
			double fTemp119 = (fConst30 * double(input24[i]));
			double fTemp120 = (fConst31 * fRec229[1]);
			double fTemp121 = (fConst32 * fRec232[1]);
			fRec234[0] = (fTemp119 + (fTemp120 + (fRec234[1] + fTemp121)));
			fRec232[0] = fRec234[0];
			double fRec233 = ((fTemp121 + fTemp120) + fTemp119);
			fRec231[0] = (fRec232[0] + fRec231[1]);
			fRec229[0] = fRec231[0];
			double fRec230 = fRec233;
			fRec228[0] = (fTemp117 + (fTemp118 + (fRec230 + fRec228[1])));
			fRec226[0] = fRec228[0];
			double fRec227 = (fTemp117 + (fRec230 + fTemp118));
			fRec225[0] = (fRec226[0] + fRec225[1]);
			fRec223[0] = fRec225[0];
			double fRec224 = fRec227;
			fRec222[0] = (fRec224 - (((fTemp1 * fRec222[2]) + (2.0 * (fTemp3 * fRec222[1]))) / fTemp4));
			double fTemp122 = (((fTemp2 * (fRec222[2] + (fRec222[0] + (2.0 * fRec222[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec222[1]) + ((fRec222[0] + fRec222[2]) / fTemp4))))));
			double fTemp123 = (fConst35 * fRec239[1]);
			double fTemp124 = (fConst38 * double(input25[i]));
			double fTemp125 = (fConst39 * fRec245[1]);
			double fTemp126 = (fConst40 * fRec248[1]);
			fRec250[0] = (fTemp124 + (fTemp125 + (fRec250[1] + fTemp126)));
			fRec248[0] = fRec250[0];
			double fRec249 = ((fTemp126 + fTemp125) + fTemp124);
			fRec247[0] = (fRec248[0] + fRec247[1]);
			fRec245[0] = fRec247[0];
			double fRec246 = fRec249;
			double fTemp127 = (fRec246 + (fConst41 * fRec242[1]));
			fRec244[0] = (fTemp123 + (fRec244[1] + fTemp127));
			fRec242[0] = fRec244[0];
			double fRec243 = (fTemp123 + fTemp127);
			fRec241[0] = (fRec242[0] + fRec241[1]);
			fRec239[0] = fRec241[0];
			double fRec240 = fRec243;
			double fTemp128 = (fRec240 + (fConst42 * fRec236[1]));
			fRec238[0] = (fRec238[1] + fTemp128);
			fRec236[0] = fRec238[0];
			double fRec237 = fTemp128;
			fRec235[0] = (fRec237 - (((fTemp1 * fRec235[2]) + (2.0 * (fTemp3 * fRec235[1]))) / fTemp4));
			double fTemp129 = (((fTemp2 * (fRec235[2] + (fRec235[0] + (2.0 * fRec235[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec235[1]) + ((fRec235[0] + fRec235[2]) / fTemp4))))));
			double fTemp130 = (fConst42 * fRec252[1]);
			double fTemp131 = (fConst35 * fRec255[1]);
			double fTemp132 = (fConst41 * fRec258[1]);
			double fTemp133 = (fConst38 * double(input31[i]));
			double fTemp134 = (fConst39 * fRec261[1]);
			double fTemp135 = (fConst40 * fRec264[1]);
			fRec266[0] = (fTemp133 + (fTemp134 + (fRec266[1] + fTemp135)));
			fRec264[0] = fRec266[0];
			double fRec265 = ((fTemp135 + fTemp134) + fTemp133);
			fRec263[0] = (fRec264[0] + fRec263[1]);
			fRec261[0] = fRec263[0];
			double fRec262 = fRec265;
			fRec260[0] = (fTemp131 + (fTemp132 + (fRec262 + fRec260[1])));
			fRec258[0] = fRec260[0];
			double fRec259 = (fTemp131 + (fRec262 + fTemp132));
			fRec257[0] = (fRec258[0] + fRec257[1]);
			fRec255[0] = fRec257[0];
			double fRec256 = fRec259;
			fRec254[0] = (fTemp130 + (fRec256 + fRec254[1]));
			fRec252[0] = fRec254[0];
			double fRec253 = (fRec256 + fTemp130);
			fRec251[0] = (fRec253 - (((fTemp1 * fRec251[2]) + (2.0 * (fTemp3 * fRec251[1]))) / fTemp4));
			double fTemp136 = (((fTemp2 * (fRec251[2] + (fRec251[0] + (2.0 * fRec251[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec251[1]) + ((fRec251[0] + fRec251[2]) / fTemp4))))));
			double fTemp137 = (fConst42 * fRec268[1]);
			double fTemp138 = (fConst35 * fRec271[1]);
			double fTemp139 = (fConst41 * fRec274[1]);
			double fTemp140 = (fConst38 * double(input32[i]));
			double fTemp141 = (fConst39 * fRec277[1]);
			double fTemp142 = (fConst40 * fRec280[1]);
			fRec282[0] = (fTemp140 + (fTemp141 + (fRec282[1] + fTemp142)));
			fRec280[0] = fRec282[0];
			double fRec281 = ((fTemp142 + fTemp141) + fTemp140);
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			fRec276[0] = (fTemp138 + (fTemp139 + (fRec278 + fRec276[1])));
			fRec274[0] = fRec276[0];
			double fRec275 = (fTemp138 + (fRec278 + fTemp139));
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			double fRec272 = fRec275;
			fRec270[0] = (fTemp137 + (fRec272 + fRec270[1]));
			fRec268[0] = fRec270[0];
			double fRec269 = (fRec272 + fTemp137);
			fRec267[0] = (fRec269 - (((fTemp1 * fRec267[2]) + (2.0 * (fTemp3 * fRec267[1]))) / fTemp4));
			double fTemp143 = (((fTemp2 * (fRec267[2] + (fRec267[0] + (2.0 * fRec267[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec267[1]) + ((fRec267[0] + fRec267[2]) / fTemp4))))));
			double fTemp144 = (fConst42 * fRec284[1]);
			double fTemp145 = (fConst35 * fRec287[1]);
			double fTemp146 = (fConst41 * fRec290[1]);
			double fTemp147 = (fConst38 * double(input33[i]));
			double fTemp148 = (fConst39 * fRec293[1]);
			double fTemp149 = (fConst40 * fRec296[1]);
			fRec298[0] = (fTemp147 + (fTemp148 + (fRec298[1] + fTemp149)));
			fRec296[0] = fRec298[0];
			double fRec297 = ((fTemp149 + fTemp148) + fTemp147);
			fRec295[0] = (fRec296[0] + fRec295[1]);
			fRec293[0] = fRec295[0];
			double fRec294 = fRec297;
			fRec292[0] = (fTemp145 + (fTemp146 + (fRec294 + fRec292[1])));
			fRec290[0] = fRec292[0];
			double fRec291 = (fTemp145 + (fRec294 + fTemp146));
			fRec289[0] = (fRec290[0] + fRec289[1]);
			fRec287[0] = fRec289[0];
			double fRec288 = fRec291;
			fRec286[0] = (fTemp144 + (fRec288 + fRec286[1]));
			fRec284[0] = fRec286[0];
			double fRec285 = (fRec288 + fTemp144);
			fRec283[0] = (fRec285 - (((fTemp1 * fRec283[2]) + (2.0 * (fTemp3 * fRec283[1]))) / fTemp4));
			double fTemp150 = (((fTemp2 * (fRec283[2] + (fRec283[0] + (2.0 * fRec283[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec283[1]) + ((fRec283[0] + fRec283[2]) / fTemp4))))));
			double fTemp151 = (fConst13 * fRec300[1]);
			double fTemp152 = (fConst12 * fRec303[1]);
			double fTemp153 = (fConst5 * fRec306[1]);
			double fTemp154 = (fConst6 * fRec309[1]);
			double fTemp155 = (fConst9 * double(input38[i]));
			double fTemp156 = (fConst10 * fRec312[1]);
			double fTemp157 = (fConst11 * fRec315[1]);
			fRec317[0] = (fTemp155 + (fTemp156 + (fRec317[1] + fTemp157)));
			fRec315[0] = fRec317[0];
			double fRec316 = ((fTemp157 + fTemp156) + fTemp155);
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			double fRec313 = fRec316;
			fRec311[0] = (fTemp153 + (fTemp154 + (fRec313 + fRec311[1])));
			fRec309[0] = fRec311[0];
			double fRec310 = (fTemp153 + (fRec313 + fTemp154));
			fRec308[0] = (fRec309[0] + fRec308[1]);
			fRec306[0] = fRec308[0];
			double fRec307 = fRec310;
			fRec305[0] = (fTemp151 + (fTemp152 + (fRec307 + fRec305[1])));
			fRec303[0] = fRec305[0];
			double fRec304 = (fTemp151 + (fRec307 + fTemp152));
			fRec302[0] = (fRec303[0] + fRec302[1]);
			fRec300[0] = fRec302[0];
			double fRec301 = fRec304;
			fRec299[0] = (fRec301 - (((fTemp1 * fRec299[2]) + (2.0 * (fTemp3 * fRec299[1]))) / fTemp4));
			double fTemp158 = (((fTemp2 * (fRec299[2] + (fRec299[0] + (2.0 * fRec299[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec299[1]) + ((fRec299[0] + fRec299[2]) / fTemp4))))));
			double fTemp159 = (fConst13 * fRec319[1]);
			double fTemp160 = (fConst12 * fRec322[1]);
			double fTemp161 = (fConst5 * fRec325[1]);
			double fTemp162 = (fConst6 * fRec328[1]);
			double fTemp163 = (fConst9 * double(input39[i]));
			double fTemp164 = (fConst10 * fRec331[1]);
			double fTemp165 = (fConst11 * fRec334[1]);
			fRec336[0] = (fTemp163 + (fTemp164 + (fRec336[1] + fTemp165)));
			fRec334[0] = fRec336[0];
			double fRec335 = ((fTemp165 + fTemp164) + fTemp163);
			fRec333[0] = (fRec334[0] + fRec333[1]);
			fRec331[0] = fRec333[0];
			double fRec332 = fRec335;
			fRec330[0] = (fTemp161 + (fTemp162 + (fRec332 + fRec330[1])));
			fRec328[0] = fRec330[0];
			double fRec329 = (fTemp161 + (fRec332 + fTemp162));
			fRec327[0] = (fRec328[0] + fRec327[1]);
			fRec325[0] = fRec327[0];
			double fRec326 = fRec329;
			fRec324[0] = (fTemp159 + (fTemp160 + (fRec326 + fRec324[1])));
			fRec322[0] = fRec324[0];
			double fRec323 = (fTemp159 + (fRec326 + fTemp160));
			fRec321[0] = (fRec322[0] + fRec321[1]);
			fRec319[0] = fRec321[0];
			double fRec320 = fRec323;
			fRec318[0] = (fRec320 - (((fTemp1 * fRec318[2]) + (2.0 * (fTemp3 * fRec318[1]))) / fTemp4));
			double fTemp166 = (((fTemp2 * (fRec318[2] + (fRec318[0] + (2.0 * fRec318[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec318[1]) + ((fRec318[0] + fRec318[2]) / fTemp4))))));
			double fTemp167 = (fConst13 * fRec338[1]);
			double fTemp168 = (fConst12 * fRec341[1]);
			double fTemp169 = (fConst5 * fRec344[1]);
			double fTemp170 = (fConst6 * fRec347[1]);
			double fTemp171 = (fConst9 * double(input40[i]));
			double fTemp172 = (fConst10 * fRec350[1]);
			double fTemp173 = (fConst11 * fRec353[1]);
			fRec355[0] = (fTemp171 + (fTemp172 + (fRec355[1] + fTemp173)));
			fRec353[0] = fRec355[0];
			double fRec354 = ((fTemp173 + fTemp172) + fTemp171);
			fRec352[0] = (fRec353[0] + fRec352[1]);
			fRec350[0] = fRec352[0];
			double fRec351 = fRec354;
			fRec349[0] = (fTemp169 + (fTemp170 + (fRec351 + fRec349[1])));
			fRec347[0] = fRec349[0];
			double fRec348 = (fTemp169 + (fRec351 + fTemp170));
			fRec346[0] = (fRec347[0] + fRec346[1]);
			fRec344[0] = fRec346[0];
			double fRec345 = fRec348;
			fRec343[0] = (fTemp167 + (fTemp168 + (fRec345 + fRec343[1])));
			fRec341[0] = fRec343[0];
			double fRec342 = (fTemp167 + (fRec345 + fTemp168));
			fRec340[0] = (fRec341[0] + fRec340[1]);
			fRec338[0] = fRec340[0];
			double fRec339 = fRec342;
			fRec337[0] = (fRec339 - (((fTemp1 * fRec337[2]) + (2.0 * (fTemp3 * fRec337[1]))) / fTemp4));
			double fTemp174 = (((fTemp2 * (fRec337[2] + (fRec337[0] + (2.0 * fRec337[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec337[1]) + ((fRec337[0] + fRec337[2]) / fTemp4))))));
			fRec356[0] = (double(input61[i]) - (((fRec356[2] * fTemp1) + (2.0 * (fRec356[1] * fTemp3))) / fTemp4));
			double fTemp175 = ((((fRec356[2] + (fRec356[0] + (2.0 * fRec356[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec356[1] * fTemp6) + ((fRec356[0] + fRec356[2]) / fTemp4))))));
			fRec357[0] = (double(input58[i]) - (((fRec357[2] * fTemp1) + (2.0 * (fRec357[1] * fTemp3))) / fTemp4));
			double fTemp176 = ((((fRec357[2] + (fRec357[0] + (2.0 * fRec357[1]))) * fTemp2) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fRec357[1] * fTemp6) + ((fRec357[0] + fRec357[2]) / fTemp4))))));
			double fTemp177 = (fConst13 * fRec359[1]);
			double fTemp178 = (fConst12 * fRec362[1]);
			double fTemp179 = (fConst5 * fRec365[1]);
			double fTemp180 = (fConst6 * fRec368[1]);
			double fTemp181 = (fConst9 * double(input48[i]));
			double fTemp182 = (fConst10 * fRec371[1]);
			double fTemp183 = (fConst11 * fRec374[1]);
			fRec376[0] = (fTemp181 + (fTemp182 + (fRec376[1] + fTemp183)));
			fRec374[0] = fRec376[0];
			double fRec375 = ((fTemp183 + fTemp182) + fTemp181);
			fRec373[0] = (fRec374[0] + fRec373[1]);
			fRec371[0] = fRec373[0];
			double fRec372 = fRec375;
			fRec370[0] = (fTemp179 + (fTemp180 + (fRec372 + fRec370[1])));
			fRec368[0] = fRec370[0];
			double fRec369 = (fTemp179 + (fRec372 + fTemp180));
			fRec367[0] = (fRec368[0] + fRec367[1]);
			fRec365[0] = fRec367[0];
			double fRec366 = fRec369;
			fRec364[0] = (fTemp177 + (fTemp178 + (fRec366 + fRec364[1])));
			fRec362[0] = fRec364[0];
			double fRec363 = (fTemp177 + (fRec366 + fTemp178));
			fRec361[0] = (fRec362[0] + fRec361[1]);
			fRec359[0] = fRec361[0];
			double fRec360 = fRec363;
			fRec358[0] = (fRec360 - (((fRec358[2] * fTemp1) + (2.0 * (fRec358[1] * fTemp3))) / fTemp4));
			double fTemp184 = ((((fRec358[2] + (fRec358[0] + (2.0 * fRec358[1]))) * fTemp2) / fTemp5) + (0.31899212910000002 * ((0.0 - ((fRec358[1] * fTemp6) + ((fRec358[0] + fRec358[2]) / fTemp4))) * fRec3[0])));
			fRec377[0] = (double(input49[i]) - (((fRec377[2] * fTemp1) + (2.0 * (fRec377[1] * fTemp3))) / fTemp4));
			double fTemp185 = ((((fRec377[2] + (fRec377[0] + (2.0 * fRec377[1]))) * fTemp2) / fTemp5) + (0.1550188129 * ((0.0 - ((fRec377[1] * fTemp6) + ((fRec377[0] + fRec377[2]) / fTemp4))) * fRec3[0])));
			double fTemp186 = (fConst18 * double(input7[i]));
			double fTemp187 = (fConst19 * fRec379[1]);
			double fTemp188 = (fConst20 * fRec382[1]);
			fRec384[0] = (fTemp186 + (fTemp187 + (fRec384[1] + fTemp188)));
			fRec382[0] = fRec384[0];
			double fRec383 = ((fTemp188 + fTemp187) + fTemp186);
			fRec381[0] = (fRec382[0] + fRec381[1]);
			fRec379[0] = fRec381[0];
			double fRec380 = fRec383;
			fRec378[0] = (fRec380 - (((fTemp1 * fRec378[2]) + (2.0 * (fTemp3 * fRec378[1]))) / fTemp4));
			double fTemp189 = (((fTemp2 * (fRec378[2] + (fRec378[0] + (2.0 * fRec378[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec378[1]) + ((fRec378[0] + fRec378[2]) / fTemp4))))));
			double fTemp190 = (fConst22 * fRec386[1]);
			double fTemp191 = (fConst24 * double(input10[i]));
			double fTemp192 = (fConst25 * fRec389[1]);
			double fTemp193 = (fConst26 * fRec392[1]);
			fRec394[0] = (fTemp191 + (fTemp192 + (fRec394[1] + fTemp193)));
			fRec392[0] = fRec394[0];
			double fRec393 = ((fTemp193 + fTemp192) + fTemp191);
			fRec391[0] = (fRec392[0] + fRec391[1]);
			fRec389[0] = fRec391[0];
			double fRec390 = fRec393;
			fRec388[0] = (fTemp190 + (fRec390 + fRec388[1]));
			fRec386[0] = fRec388[0];
			double fRec387 = (fRec390 + fTemp190);
			fRec385[0] = (fRec387 - (((fTemp1 * fRec385[2]) + (2.0 * (fTemp3 * fRec385[1]))) / fTemp4));
			double fTemp194 = (((fTemp2 * (fRec385[2] + (fRec385[0] + (2.0 * fRec385[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec385[1]) + ((fRec385[0] + fRec385[2]) / fTemp4))))));
			double fTemp195 = (fConst22 * fRec396[1]);
			double fTemp196 = (fConst24 * double(input11[i]));
			double fTemp197 = (fConst25 * fRec399[1]);
			double fTemp198 = (fConst26 * fRec402[1]);
			fRec404[0] = (fTemp196 + (fTemp197 + (fRec404[1] + fTemp198)));
			fRec402[0] = fRec404[0];
			double fRec403 = ((fTemp198 + fTemp197) + fTemp196);
			fRec401[0] = (fRec402[0] + fRec401[1]);
			fRec399[0] = fRec401[0];
			double fRec400 = fRec403;
			fRec398[0] = (fTemp195 + (fRec400 + fRec398[1]));
			fRec396[0] = fRec398[0];
			double fRec397 = (fRec400 + fTemp195);
			fRec395[0] = (fRec397 - (((fTemp1 * fRec395[2]) + (2.0 * (fTemp3 * fRec395[1]))) / fTemp4));
			double fTemp199 = (((fTemp2 * (fRec395[2] + (fRec395[0] + (2.0 * fRec395[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec395[1]) + ((fRec395[0] + fRec395[2]) / fTemp4))))));
			double fTemp200 = (fConst22 * fRec406[1]);
			double fTemp201 = (fConst24 * double(input12[i]));
			double fTemp202 = (fConst25 * fRec409[1]);
			double fTemp203 = (fConst26 * fRec412[1]);
			fRec414[0] = (fTemp201 + (fTemp202 + (fRec414[1] + fTemp203)));
			fRec412[0] = fRec414[0];
			double fRec413 = ((fTemp203 + fTemp202) + fTemp201);
			fRec411[0] = (fRec412[0] + fRec411[1]);
			fRec409[0] = fRec411[0];
			double fRec410 = fRec413;
			fRec408[0] = (fTemp200 + (fRec410 + fRec408[1]));
			fRec406[0] = fRec408[0];
			double fRec407 = (fRec410 + fTemp200);
			fRec405[0] = (fRec407 - (((fTemp1 * fRec405[2]) + (2.0 * (fTemp3 * fRec405[1]))) / fTemp4));
			double fTemp204 = (((fTemp2 * (fRec405[2] + (fRec405[0] + (2.0 * fRec405[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec405[1]) + ((fRec405[0] + fRec405[2]) / fTemp4))))));
			double fTemp205 = (fConst22 * fRec416[1]);
			double fTemp206 = (fConst24 * double(input13[i]));
			double fTemp207 = (fConst25 * fRec419[1]);
			double fTemp208 = (fConst26 * fRec422[1]);
			fRec424[0] = (fTemp206 + (fTemp207 + (fRec424[1] + fTemp208)));
			fRec422[0] = fRec424[0];
			double fRec423 = ((fTemp208 + fTemp207) + fTemp206);
			fRec421[0] = (fRec422[0] + fRec421[1]);
			fRec419[0] = fRec421[0];
			double fRec420 = fRec423;
			fRec418[0] = (fTemp205 + (fRec420 + fRec418[1]));
			fRec416[0] = fRec418[0];
			double fRec417 = (fRec420 + fTemp205);
			fRec415[0] = (fRec417 - (((fTemp1 * fRec415[2]) + (2.0 * (fTemp3 * fRec415[1]))) / fTemp4));
			double fTemp209 = (((fTemp2 * (fRec415[2] + (fRec415[0] + (2.0 * fRec415[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec415[1]) + ((fRec415[0] + fRec415[2]) / fTemp4))))));
			double fTemp210 = (fConst22 * fRec426[1]);
			double fTemp211 = (fConst24 * double(input14[i]));
			double fTemp212 = (fConst25 * fRec429[1]);
			double fTemp213 = (fConst26 * fRec432[1]);
			fRec434[0] = (fTemp211 + (fTemp212 + (fRec434[1] + fTemp213)));
			fRec432[0] = fRec434[0];
			double fRec433 = ((fTemp213 + fTemp212) + fTemp211);
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			fRec428[0] = (fTemp210 + (fRec430 + fRec428[1]));
			fRec426[0] = fRec428[0];
			double fRec427 = (fRec430 + fTemp210);
			fRec425[0] = (fRec427 - (((fTemp1 * fRec425[2]) + (2.0 * (fTemp3 * fRec425[1]))) / fTemp4));
			double fTemp214 = (((fTemp2 * (fRec425[2] + (fRec425[0] + (2.0 * fRec425[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec425[1]) + ((fRec425[0] + fRec425[2]) / fTemp4))))));
			double fTemp215 = (fConst28 * fRec436[1]);
			double fTemp216 = (fConst33 * fRec439[1]);
			double fTemp217 = (fConst30 * double(input17[i]));
			double fTemp218 = (fConst31 * fRec442[1]);
			double fTemp219 = (fConst32 * fRec445[1]);
			fRec447[0] = (fTemp217 + (fTemp218 + (fRec447[1] + fTemp219)));
			fRec445[0] = fRec447[0];
			double fRec446 = ((fTemp219 + fTemp218) + fTemp217);
			fRec444[0] = (fRec445[0] + fRec444[1]);
			fRec442[0] = fRec444[0];
			double fRec443 = fRec446;
			fRec441[0] = (fTemp215 + (fTemp216 + (fRec443 + fRec441[1])));
			fRec439[0] = fRec441[0];
			double fRec440 = (fTemp215 + (fRec443 + fTemp216));
			fRec438[0] = (fRec439[0] + fRec438[1]);
			fRec436[0] = fRec438[0];
			double fRec437 = fRec440;
			fRec435[0] = (fRec437 - (((fTemp1 * fRec435[2]) + (2.0 * (fTemp3 * fRec435[1]))) / fTemp4));
			double fTemp220 = (((fTemp2 * (fRec435[2] + (fRec435[0] + (2.0 * fRec435[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec435[1]) + ((fRec435[0] + fRec435[2]) / fTemp4))))));
			double fTemp221 = (fConst28 * fRec449[1]);
			double fTemp222 = (fConst33 * fRec452[1]);
			double fTemp223 = (fConst30 * double(input18[i]));
			double fTemp224 = (fConst31 * fRec455[1]);
			double fTemp225 = (fConst32 * fRec458[1]);
			fRec460[0] = (fTemp223 + (fTemp224 + (fRec460[1] + fTemp225)));
			fRec458[0] = fRec460[0];
			double fRec459 = ((fTemp225 + fTemp224) + fTemp223);
			fRec457[0] = (fRec458[0] + fRec457[1]);
			fRec455[0] = fRec457[0];
			double fRec456 = fRec459;
			fRec454[0] = (fTemp221 + (fTemp222 + (fRec456 + fRec454[1])));
			fRec452[0] = fRec454[0];
			double fRec453 = (fTemp221 + (fRec456 + fTemp222));
			fRec451[0] = (fRec452[0] + fRec451[1]);
			fRec449[0] = fRec451[0];
			double fRec450 = fRec453;
			fRec448[0] = (fRec450 - (((fTemp1 * fRec448[2]) + (2.0 * (fTemp3 * fRec448[1]))) / fTemp4));
			double fTemp226 = (((fTemp2 * (fRec448[2] + (fRec448[0] + (2.0 * fRec448[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec448[1]) + ((fRec448[0] + fRec448[2]) / fTemp4))))));
			double fTemp227 = (fConst28 * fRec462[1]);
			double fTemp228 = (fConst33 * fRec465[1]);
			double fTemp229 = (fConst30 * double(input19[i]));
			double fTemp230 = (fConst31 * fRec468[1]);
			double fTemp231 = (fConst32 * fRec471[1]);
			fRec473[0] = (fTemp229 + (fTemp230 + (fRec473[1] + fTemp231)));
			fRec471[0] = fRec473[0];
			double fRec472 = ((fTemp231 + fTemp230) + fTemp229);
			fRec470[0] = (fRec471[0] + fRec470[1]);
			fRec468[0] = fRec470[0];
			double fRec469 = fRec472;
			fRec467[0] = (fTemp227 + (fTemp228 + (fRec469 + fRec467[1])));
			fRec465[0] = fRec467[0];
			double fRec466 = (fTemp227 + (fRec469 + fTemp228));
			fRec464[0] = (fRec465[0] + fRec464[1]);
			fRec462[0] = fRec464[0];
			double fRec463 = fRec466;
			fRec461[0] = (fRec463 - (((fTemp1 * fRec461[2]) + (2.0 * (fTemp3 * fRec461[1]))) / fTemp4));
			double fTemp232 = (((fTemp2 * (fRec461[2] + (fRec461[0] + (2.0 * fRec461[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec461[1]) + ((fRec461[0] + fRec461[2]) / fTemp4))))));
			double fTemp233 = (fConst28 * fRec475[1]);
			double fTemp234 = (fConst33 * fRec478[1]);
			double fTemp235 = (fConst30 * double(input20[i]));
			double fTemp236 = (fConst31 * fRec481[1]);
			double fTemp237 = (fConst32 * fRec484[1]);
			fRec486[0] = (fTemp235 + (fTemp236 + (fRec486[1] + fTemp237)));
			fRec484[0] = fRec486[0];
			double fRec485 = ((fTemp237 + fTemp236) + fTemp235);
			fRec483[0] = (fRec484[0] + fRec483[1]);
			fRec481[0] = fRec483[0];
			double fRec482 = fRec485;
			fRec480[0] = (fTemp233 + (fTemp234 + (fRec482 + fRec480[1])));
			fRec478[0] = fRec480[0];
			double fRec479 = (fTemp233 + (fRec482 + fTemp234));
			fRec477[0] = (fRec478[0] + fRec477[1]);
			fRec475[0] = fRec477[0];
			double fRec476 = fRec479;
			fRec474[0] = (fRec476 - (((fTemp1 * fRec474[2]) + (2.0 * (fTemp3 * fRec474[1]))) / fTemp4));
			double fTemp238 = (((fTemp2 * (fRec474[2] + (fRec474[0] + (2.0 * fRec474[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec474[1]) + ((fRec474[0] + fRec474[2]) / fTemp4))))));
			double fTemp239 = (fConst28 * fRec488[1]);
			double fTemp240 = (fConst33 * fRec491[1]);
			double fTemp241 = (fConst30 * double(input21[i]));
			double fTemp242 = (fConst31 * fRec494[1]);
			double fTemp243 = (fConst32 * fRec497[1]);
			fRec499[0] = (fTemp241 + (fTemp242 + (fRec499[1] + fTemp243)));
			fRec497[0] = fRec499[0];
			double fRec498 = ((fTemp243 + fTemp242) + fTemp241);
			fRec496[0] = (fRec497[0] + fRec496[1]);
			fRec494[0] = fRec496[0];
			double fRec495 = fRec498;
			fRec493[0] = (fTemp239 + (fTemp240 + (fRec495 + fRec493[1])));
			fRec491[0] = fRec493[0];
			double fRec492 = (fTemp239 + (fRec495 + fTemp240));
			fRec490[0] = (fRec491[0] + fRec490[1]);
			fRec488[0] = fRec490[0];
			double fRec489 = fRec492;
			fRec487[0] = (fRec489 - (((fTemp1 * fRec487[2]) + (2.0 * (fTemp3 * fRec487[1]))) / fTemp4));
			double fTemp244 = (((fTemp2 * (fRec487[2] + (fRec487[0] + (2.0 * fRec487[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec487[1]) + ((fRec487[0] + fRec487[2]) / fTemp4))))));
			double fTemp245 = (fConst28 * fRec501[1]);
			double fTemp246 = (fConst33 * fRec504[1]);
			double fTemp247 = (fConst30 * double(input22[i]));
			double fTemp248 = (fConst31 * fRec507[1]);
			double fTemp249 = (fConst32 * fRec510[1]);
			fRec512[0] = (fTemp247 + (fTemp248 + (fRec512[1] + fTemp249)));
			fRec510[0] = fRec512[0];
			double fRec511 = ((fTemp249 + fTemp248) + fTemp247);
			fRec509[0] = (fRec510[0] + fRec509[1]);
			fRec507[0] = fRec509[0];
			double fRec508 = fRec511;
			fRec506[0] = (fTemp245 + (fTemp246 + (fRec508 + fRec506[1])));
			fRec504[0] = fRec506[0];
			double fRec505 = (fTemp245 + (fRec508 + fTemp246));
			fRec503[0] = (fRec504[0] + fRec503[1]);
			fRec501[0] = fRec503[0];
			double fRec502 = fRec505;
			fRec500[0] = (fRec502 - (((fTemp1 * fRec500[2]) + (2.0 * (fTemp3 * fRec500[1]))) / fTemp4));
			double fTemp250 = (((fTemp2 * (fRec500[2] + (fRec500[0] + (2.0 * fRec500[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec500[1]) + ((fRec500[0] + fRec500[2]) / fTemp4))))));
			double fTemp251 = (fConst28 * fRec514[1]);
			double fTemp252 = (fConst33 * fRec517[1]);
			double fTemp253 = (fConst30 * double(input23[i]));
			double fTemp254 = (fConst31 * fRec520[1]);
			double fTemp255 = (fConst32 * fRec523[1]);
			fRec525[0] = (fTemp253 + (fTemp254 + (fRec525[1] + fTemp255)));
			fRec523[0] = fRec525[0];
			double fRec524 = ((fTemp255 + fTemp254) + fTemp253);
			fRec522[0] = (fRec523[0] + fRec522[1]);
			fRec520[0] = fRec522[0];
			double fRec521 = fRec524;
			fRec519[0] = (fTemp251 + (fTemp252 + (fRec521 + fRec519[1])));
			fRec517[0] = fRec519[0];
			double fRec518 = (fTemp251 + (fRec521 + fTemp252));
			fRec516[0] = (fRec517[0] + fRec516[1]);
			fRec514[0] = fRec516[0];
			double fRec515 = fRec518;
			fRec513[0] = (fRec515 - (((fTemp1 * fRec513[2]) + (2.0 * (fTemp3 * fRec513[1]))) / fTemp4));
			double fTemp256 = (((fTemp2 * (fRec513[2] + (fRec513[0] + (2.0 * fRec513[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec513[1]) + ((fRec513[0] + fRec513[2]) / fTemp4))))));
			double fTemp257 = (fConst42 * fRec527[1]);
			double fTemp258 = (fConst35 * fRec530[1]);
			double fTemp259 = (fConst41 * fRec533[1]);
			double fTemp260 = (fConst38 * double(input26[i]));
			double fTemp261 = (fConst39 * fRec536[1]);
			double fTemp262 = (fConst40 * fRec539[1]);
			fRec541[0] = (fTemp260 + (fTemp261 + (fRec541[1] + fTemp262)));
			fRec539[0] = fRec541[0];
			double fRec540 = ((fTemp262 + fTemp261) + fTemp260);
			fRec538[0] = (fRec539[0] + fRec538[1]);
			fRec536[0] = fRec538[0];
			double fRec537 = fRec540;
			fRec535[0] = (fTemp258 + (fTemp259 + (fRec537 + fRec535[1])));
			fRec533[0] = fRec535[0];
			double fRec534 = (fTemp258 + (fRec537 + fTemp259));
			fRec532[0] = (fRec533[0] + fRec532[1]);
			fRec530[0] = fRec532[0];
			double fRec531 = fRec534;
			fRec529[0] = (fTemp257 + (fRec531 + fRec529[1]));
			fRec527[0] = fRec529[0];
			double fRec528 = (fRec531 + fTemp257);
			fRec526[0] = (fRec528 - (((fTemp1 * fRec526[2]) + (2.0 * (fTemp3 * fRec526[1]))) / fTemp4));
			double fTemp263 = (((fTemp2 * (fRec526[2] + (fRec526[0] + (2.0 * fRec526[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec526[1]) + ((fRec526[0] + fRec526[2]) / fTemp4))))));
			double fTemp264 = (fConst42 * fRec543[1]);
			double fTemp265 = (fConst35 * fRec546[1]);
			double fTemp266 = (fConst41 * fRec549[1]);
			double fTemp267 = (fConst38 * double(input27[i]));
			double fTemp268 = (fConst39 * fRec552[1]);
			double fTemp269 = (fConst40 * fRec555[1]);
			fRec557[0] = (fTemp267 + (fTemp268 + (fRec557[1] + fTemp269)));
			fRec555[0] = fRec557[0];
			double fRec556 = ((fTemp269 + fTemp268) + fTemp267);
			fRec554[0] = (fRec555[0] + fRec554[1]);
			fRec552[0] = fRec554[0];
			double fRec553 = fRec556;
			fRec551[0] = (fTemp265 + (fTemp266 + (fRec553 + fRec551[1])));
			fRec549[0] = fRec551[0];
			double fRec550 = (fTemp265 + (fRec553 + fTemp266));
			fRec548[0] = (fRec549[0] + fRec548[1]);
			fRec546[0] = fRec548[0];
			double fRec547 = fRec550;
			fRec545[0] = (fTemp264 + (fRec547 + fRec545[1]));
			fRec543[0] = fRec545[0];
			double fRec544 = (fRec547 + fTemp264);
			fRec542[0] = (fRec544 - (((fTemp1 * fRec542[2]) + (2.0 * (fTemp3 * fRec542[1]))) / fTemp4));
			double fTemp270 = (((fTemp2 * (fRec542[2] + (fRec542[0] + (2.0 * fRec542[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec542[1]) + ((fRec542[0] + fRec542[2]) / fTemp4))))));
			double fTemp271 = (fConst42 * fRec559[1]);
			double fTemp272 = (fConst35 * fRec562[1]);
			double fTemp273 = (fConst41 * fRec565[1]);
			double fTemp274 = (fConst38 * double(input28[i]));
			double fTemp275 = (fConst39 * fRec568[1]);
			double fTemp276 = (fConst40 * fRec571[1]);
			fRec573[0] = (fTemp274 + (fTemp275 + (fRec573[1] + fTemp276)));
			fRec571[0] = fRec573[0];
			double fRec572 = ((fTemp276 + fTemp275) + fTemp274);
			fRec570[0] = (fRec571[0] + fRec570[1]);
			fRec568[0] = fRec570[0];
			double fRec569 = fRec572;
			fRec567[0] = (fTemp272 + (fTemp273 + (fRec569 + fRec567[1])));
			fRec565[0] = fRec567[0];
			double fRec566 = (fTemp272 + (fRec569 + fTemp273));
			fRec564[0] = (fRec565[0] + fRec564[1]);
			fRec562[0] = fRec564[0];
			double fRec563 = fRec566;
			fRec561[0] = (fTemp271 + (fRec563 + fRec561[1]));
			fRec559[0] = fRec561[0];
			double fRec560 = (fRec563 + fTemp271);
			fRec558[0] = (fRec560 - (((fTemp1 * fRec558[2]) + (2.0 * (fTemp3 * fRec558[1]))) / fTemp4));
			double fTemp277 = (((fTemp2 * (fRec558[2] + (fRec558[0] + (2.0 * fRec558[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec558[1]) + ((fRec558[0] + fRec558[2]) / fTemp4))))));
			double fTemp278 = (fConst42 * fRec575[1]);
			double fTemp279 = (fConst35 * fRec578[1]);
			double fTemp280 = (fConst41 * fRec581[1]);
			double fTemp281 = (fConst38 * double(input29[i]));
			double fTemp282 = (fConst39 * fRec584[1]);
			double fTemp283 = (fConst40 * fRec587[1]);
			fRec589[0] = (fTemp281 + (fTemp282 + (fRec589[1] + fTemp283)));
			fRec587[0] = fRec589[0];
			double fRec588 = ((fTemp283 + fTemp282) + fTemp281);
			fRec586[0] = (fRec587[0] + fRec586[1]);
			fRec584[0] = fRec586[0];
			double fRec585 = fRec588;
			fRec583[0] = (fTemp279 + (fTemp280 + (fRec585 + fRec583[1])));
			fRec581[0] = fRec583[0];
			double fRec582 = (fTemp279 + (fRec585 + fTemp280));
			fRec580[0] = (fRec581[0] + fRec580[1]);
			fRec578[0] = fRec580[0];
			double fRec579 = fRec582;
			fRec577[0] = (fTemp278 + (fRec579 + fRec577[1]));
			fRec575[0] = fRec577[0];
			double fRec576 = (fRec579 + fTemp278);
			fRec574[0] = (fRec576 - (((fTemp1 * fRec574[2]) + (2.0 * (fTemp3 * fRec574[1]))) / fTemp4));
			double fTemp284 = (((fTemp2 * (fRec574[2] + (fRec574[0] + (2.0 * fRec574[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec574[1]) + ((fRec574[0] + fRec574[2]) / fTemp4))))));
			double fTemp285 = (fConst42 * fRec591[1]);
			double fTemp286 = (fConst35 * fRec594[1]);
			double fTemp287 = (fConst41 * fRec597[1]);
			double fTemp288 = (fConst38 * double(input30[i]));
			double fTemp289 = (fConst39 * fRec600[1]);
			double fTemp290 = (fConst40 * fRec603[1]);
			fRec605[0] = (fTemp288 + (fTemp289 + (fRec605[1] + fTemp290)));
			fRec603[0] = fRec605[0];
			double fRec604 = ((fTemp290 + fTemp289) + fTemp288);
			fRec602[0] = (fRec603[0] + fRec602[1]);
			fRec600[0] = fRec602[0];
			double fRec601 = fRec604;
			fRec599[0] = (fTemp286 + (fTemp287 + (fRec601 + fRec599[1])));
			fRec597[0] = fRec599[0];
			double fRec598 = (fTemp286 + (fRec601 + fTemp287));
			fRec596[0] = (fRec597[0] + fRec596[1]);
			fRec594[0] = fRec596[0];
			double fRec595 = fRec598;
			fRec593[0] = (fTemp285 + (fRec595 + fRec593[1]));
			fRec591[0] = fRec593[0];
			double fRec592 = (fRec595 + fTemp285);
			fRec590[0] = (fRec592 - (((fTemp1 * fRec590[2]) + (2.0 * (fTemp3 * fRec590[1]))) / fTemp4));
			double fTemp291 = (((fTemp2 * (fRec590[2] + (fRec590[0] + (2.0 * fRec590[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec590[1]) + ((fRec590[0] + fRec590[2]) / fTemp4))))));
			double fTemp292 = (fConst42 * fRec607[1]);
			double fTemp293 = (fConst35 * fRec610[1]);
			double fTemp294 = (fConst41 * fRec613[1]);
			double fTemp295 = (fConst38 * double(input34[i]));
			double fTemp296 = (fConst39 * fRec616[1]);
			double fTemp297 = (fConst40 * fRec619[1]);
			fRec621[0] = (fTemp295 + (fTemp296 + (fRec621[1] + fTemp297)));
			fRec619[0] = fRec621[0];
			double fRec620 = ((fTemp297 + fTemp296) + fTemp295);
			fRec618[0] = (fRec619[0] + fRec618[1]);
			fRec616[0] = fRec618[0];
			double fRec617 = fRec620;
			fRec615[0] = (fTemp293 + (fTemp294 + (fRec617 + fRec615[1])));
			fRec613[0] = fRec615[0];
			double fRec614 = (fTemp293 + (fRec617 + fTemp294));
			fRec612[0] = (fRec613[0] + fRec612[1]);
			fRec610[0] = fRec612[0];
			double fRec611 = fRec614;
			fRec609[0] = (fTemp292 + (fRec611 + fRec609[1]));
			fRec607[0] = fRec609[0];
			double fRec608 = (fRec611 + fTemp292);
			fRec606[0] = (fRec608 - (((fTemp1 * fRec606[2]) + (2.0 * (fTemp3 * fRec606[1]))) / fTemp4));
			double fTemp298 = (((fTemp2 * (fRec606[2] + (fRec606[0] + (2.0 * fRec606[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec606[1]) + ((fRec606[0] + fRec606[2]) / fTemp4))))));
			double fTemp299 = (fConst42 * fRec623[1]);
			double fTemp300 = (fConst35 * fRec626[1]);
			double fTemp301 = (fConst41 * fRec629[1]);
			double fTemp302 = (fConst38 * double(input35[i]));
			double fTemp303 = (fConst39 * fRec632[1]);
			double fTemp304 = (fConst40 * fRec635[1]);
			fRec637[0] = (fTemp302 + (fTemp303 + (fRec637[1] + fTemp304)));
			fRec635[0] = fRec637[0];
			double fRec636 = ((fTemp304 + fTemp303) + fTemp302);
			fRec634[0] = (fRec635[0] + fRec634[1]);
			fRec632[0] = fRec634[0];
			double fRec633 = fRec636;
			fRec631[0] = (fTemp300 + (fTemp301 + (fRec633 + fRec631[1])));
			fRec629[0] = fRec631[0];
			double fRec630 = (fTemp300 + (fRec633 + fTemp301));
			fRec628[0] = (fRec629[0] + fRec628[1]);
			fRec626[0] = fRec628[0];
			double fRec627 = fRec630;
			fRec625[0] = (fTemp299 + (fRec627 + fRec625[1]));
			fRec623[0] = fRec625[0];
			double fRec624 = (fRec627 + fTemp299);
			fRec622[0] = (fRec624 - (((fTemp1 * fRec622[2]) + (2.0 * (fTemp3 * fRec622[1]))) / fTemp4));
			double fTemp305 = (((fTemp2 * (fRec622[2] + (fRec622[0] + (2.0 * fRec622[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec622[1]) + ((fRec622[0] + fRec622[2]) / fTemp4))))));
			double fTemp306 = (fConst5 * fRec645[1]);
			double fTemp307 = (fConst6 * fRec648[1]);
			double fTemp308 = (fConst9 * double(input36[i]));
			double fTemp309 = (fConst10 * fRec651[1]);
			double fTemp310 = (fConst11 * fRec654[1]);
			fRec656[0] = (fTemp308 + (fTemp309 + (fRec656[1] + fTemp310)));
			fRec654[0] = fRec656[0];
			double fRec655 = ((fTemp310 + fTemp309) + fTemp308);
			fRec653[0] = (fRec654[0] + fRec653[1]);
			fRec651[0] = fRec653[0];
			double fRec652 = fRec655;
			fRec650[0] = (fTemp306 + (fTemp307 + (fRec652 + fRec650[1])));
			fRec648[0] = fRec650[0];
			double fRec649 = (fTemp306 + (fRec652 + fTemp307));
			fRec647[0] = (fRec648[0] + fRec647[1]);
			fRec645[0] = fRec647[0];
			double fRec646 = fRec649;
			double fTemp311 = ((fConst13 * fRec639[1]) + (fRec646 + (fConst12 * fRec642[1])));
			fRec644[0] = (fRec644[1] + fTemp311);
			fRec642[0] = fRec644[0];
			double fRec643 = fTemp311;
			fRec641[0] = (fRec642[0] + fRec641[1]);
			fRec639[0] = fRec641[0];
			double fRec640 = fRec643;
			fRec638[0] = (fRec640 - (((fTemp1 * fRec638[2]) + (2.0 * (fTemp3 * fRec638[1]))) / fTemp4));
			double fTemp312 = (((fTemp2 * (fRec638[2] + (fRec638[0] + (2.0 * fRec638[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec638[1]) + ((fRec638[0] + fRec638[2]) / fTemp4))))));
			double fTemp313 = (fConst13 * fRec658[1]);
			double fTemp314 = (fConst12 * fRec661[1]);
			double fTemp315 = (fConst5 * fRec664[1]);
			double fTemp316 = (fConst6 * fRec667[1]);
			double fTemp317 = (fConst9 * double(input37[i]));
			double fTemp318 = (fConst10 * fRec670[1]);
			double fTemp319 = (fConst11 * fRec673[1]);
			fRec675[0] = (fTemp317 + (fTemp318 + (fRec675[1] + fTemp319)));
			fRec673[0] = fRec675[0];
			double fRec674 = ((fTemp319 + fTemp318) + fTemp317);
			fRec672[0] = (fRec673[0] + fRec672[1]);
			fRec670[0] = fRec672[0];
			double fRec671 = fRec674;
			fRec669[0] = (fTemp315 + (fTemp316 + (fRec671 + fRec669[1])));
			fRec667[0] = fRec669[0];
			double fRec668 = (fTemp315 + (fRec671 + fTemp316));
			fRec666[0] = (fRec667[0] + fRec666[1]);
			fRec664[0] = fRec666[0];
			double fRec665 = fRec668;
			fRec663[0] = (fTemp313 + (fTemp314 + (fRec665 + fRec663[1])));
			fRec661[0] = fRec663[0];
			double fRec662 = (fTemp313 + (fRec665 + fTemp314));
			fRec660[0] = (fRec661[0] + fRec660[1]);
			fRec658[0] = fRec660[0];
			double fRec659 = fRec662;
			fRec657[0] = (fRec659 - (((fTemp1 * fRec657[2]) + (2.0 * (fTemp3 * fRec657[1]))) / fTemp4));
			double fTemp320 = (((fTemp2 * (fRec657[2] + (fRec657[0] + (2.0 * fRec657[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec657[1]) + ((fRec657[0] + fRec657[2]) / fTemp4))))));
			output0[i] = FAUSTFLOAT((fRec0[0] * ((((((((((((((((((((((0.0126982689 * fTemp7) + ((0.015631128500000001 * fTemp8) + ((7.8226999999999995e-05 * fTemp9) + ((0.0180143647 * fTemp10) + ((0.0083166236999999994 * fTemp11) + ((0.038586164300000003 * fTemp12) + ((0.036875303399999997 * fTemp13) + ((0.021374965100000001 * fTemp14) + ((0.055317898599999998 * fTemp15) + ((0.016387797499999999 * fTemp16) + ((0.020434134 * fTemp17) + ((((((((0.038022088000000002 * fTemp25) + (0.068936328300000002 * fTemp33)) + (0.069924541500000006 * fTemp41)) + (0.039746911699999998 * fTemp49)) + (0.015120098 * fTemp57)) + (0.0038114848999999998 * fTemp65)) + (0.029127551799999998 * fTemp73)) + (0.0039992964000000004 * fTemp74))))))))))))) + (0.317270681 * fTemp75)) + (0.1591965169 * fTemp78)) + (0.38690982149999997 * fTemp81)) + (0.26980846219999999 * fTemp84)) + (0.1675597563 * fTemp88)) + (0.061327121300000002 * fTemp92)) + (0.1281750224 * fTemp96)) + (0.1633572797 * fTemp100)) + (0.136132053 * fTemp105)) + (0.059499020899999998 * fTemp110)) + (0.089899030599999999 * fTemp116)) + (0.00013741609999999999 * fTemp122)) + (0.0288571208 * fTemp129)) + (0.035310906400000001 * fTemp136)) + (0.0093012705000000001 * fTemp143)) + (0.0088112574999999992 * fTemp150)) + (0.0278822681 * fTemp158)) + (0.020610271100000001 * fTemp166)) + (0.047111321900000003 * fTemp174)) - ((((((((((((((((((((((((0.0070879280999999999 * fTemp175) + ((0.01246219 * fTemp176) + ((0.010880222599999999 * fTemp184) + (0.0223500656 * fTemp185)))) + (0.035653193999999999 * fTemp189)) + (0.076770925200000006 * fTemp194)) + (0.0161948601 * fTemp199)) + (0.059412464599999999 * fTemp204)) + (0.0932789698 * fTemp209)) + (0.095970670100000002 * fTemp214)) + (0.1321915699 * fTemp220)) + (0.040803211499999999 * fTemp226)) + (0.062826274599999996 * fTemp232)) + (0.13619106580000001 * fTemp238)) + (0.051955682000000003 * fTemp244)) + (0.019975113400000001 * fTemp250)) + (0.064702650099999995 * fTemp256)) + (0.098572700999999999 * fTemp263)) + (0.0029427143 * fTemp270)) + (0.016705369500000001 * fTemp277)) + (0.025516530900000001 * fTemp284)) + (0.0079977493000000007 * fTemp291)) + (0.0030743347 * fTemp298)) + (0.017720748299999999 * fTemp305)) + (0.0093442449999999993 * fTemp312)) + (0.047305430199999998 * fTemp320)))));
			output1[i] = FAUSTFLOAT((fRec0[0] * (((0.041179443199999999 * fTemp320) + ((0.0033663922999999998 * fTemp312) + ((0.023599542500000001 * fTemp150) + ((0.053607675399999999 * fTemp143) + ((0.038192298800000003 * fTemp136) + ((0.038278068800000002 * fTemp291) + ((0.024636241999999999 * fTemp284) + ((0.022622588400000001 * fTemp277) + ((0.0089263775000000007 * fTemp270) + ((0.080128333800000007 * fTemp263) + ((0.017896827300000001 * fTemp244) + ((0.0012185886 * fTemp238) + ((0.072098914599999994 * fTemp232) + ((0.023222474999999999 * fTemp226) + ((0.11941379840000001 * fTemp220) + ((0.043426864199999998 * fTemp110) + ((0.023519050100000001 * fTemp199) + ((0.040330365600000001 * fTemp194) + ((0.1003268831 * fTemp100) + ((0.21658543760000001 * fTemp84) + ((0.12391850729999999 * fTemp75) + ((0.0123704768 * fTemp7) + ((0.025231403699999998 * fTemp8) + ((0.0057183457000000004 * fTemp9) + ((0.0045652215999999997 * fTemp10) + (((0.024547033100000001 * fTemp73) + ((0.013889677099999999 * fTemp65) + ((0.027772346600000001 * fTemp57) + ((0.058674676600000003 * fTemp49) + ((0.010351164 * fTemp33) + (0.0039142326999999999 * fTemp41)))))) + (0.020537663500000001 * fTemp185))))))))))))))))))))))))))) - ((0.038401610799999999 * fTemp174) + ((0.0057157744 * fTemp166) + ((0.031041959899999999 * fTemp158) + ((0.021967483199999999 * fTemp305) + ((0.0016196148 * fTemp298) + ((0.038208468199999998 * fTemp129) + ((0.0049716185999999999 * fTemp122) + ((0.071366385700000007 * fTemp256) + ((0.024383645900000001 * fTemp250) + ((0.1079463487 * fTemp116) + ((0.16368610650000001 * fTemp214) + ((0.059496423299999997 * fTemp209) + ((0.026387006099999999 * fTemp204) + ((0.15196916360000001 * fTemp105) + ((0.081576486899999995 * fTemp189) + ((0.1113339468 * fTemp96) + ((0.063065545799999997 * fTemp92) + ((0.19502253450000001 * fTemp88) + ((0.0027528449999999999 * fTemp81) + ((0.16358085150000001 * fTemp78) + ((0.0097038860999999997 * fTemp175) + ((0.040724135699999997 * fTemp176) + ((0.0258944251 * fTemp11) + ((0.019829757 * fTemp12) + ((0.040597278100000002 * fTemp13) + ((0.023705013600000002 * fTemp14) + ((0.053450726499999997 * fTemp15) + ((0.0096765515999999996 * fTemp16) + ((0.015962195700000001 * fTemp17) + ((0.0081480232999999996 * fTemp74) + ((0.047047534199999998 * fTemp25) + (0.0047121397000000004 * fTemp184)))))))))))))))))))))))))))))))))));
			output2[i] = FAUSTFLOAT((fRec0[0] * (((0.021848346599999999 * fTemp158) + ((0.059486059299999998 * fTemp305) + ((0.021864456000000001 * fTemp298) + ((0.0074600011000000004 * fTemp136) + ((0.022701391200000001 * fTemp129) + ((0.014782942699999999 * fTemp122) + ((0.13718573540000001 * fTemp256) + ((0.0325313058 * fTemp250) + ((0.036442935400000001 * fTemp244) + ((0.035535765800000001 * fTemp238) + ((0.1084260885 * fTemp116) + ((0.084473316100000001 * fTemp214) + ((0.062807010199999999 * fTemp204) + ((0.0591341851 * fTemp199) + ((0.1145587639 * fTemp194) + ((0.081443541499999994 * fTemp105) + ((0.1103436785 * fTemp92) + ((0.053293781599999999 * fTemp84) + ((0.066840562399999998 * fTemp75) + ((0.0070351221 * fTemp7) + ((0.0134407285 * fTemp175) + ((0.0027325409000000002 * fTemp12) + ((0.045297348500000001 * fTemp13) + ((0.051313218799999998 * fTemp14) + ((0.034746096099999998 * fTemp15) + ((0.0181872309 * fTemp16) + ((0.023137672500000001 * fTemp17) + (((0.0098574162 * fTemp25) + (0.0233380607 * fTemp184)) + (0.0174800079 * fTemp74))))))))))))))))))))))))))))) - ((0.022841354599999999 * fTemp174) + ((0.017572439700000001 * fTemp166) + ((0.041431804000000003 * fTemp320) + ((0.014563515799999999 * fTemp312) + ((0.0199165187 * fTemp150) + ((0.0033486990000000001 * fTemp143) + ((0.016642768700000001 * fTemp291) + ((0.053628486599999997 * fTemp284) + ((0.045237052700000002 * fTemp277) + ((0.0236273795 * fTemp270) + ((0.1139549228 * fTemp263) + ((0.043949556399999999 * fTemp232) + ((0.0064837081 * fTemp226) + ((0.028530001499999999 * fTemp220) + ((0.13185859189999999 * fTemp110) + ((0.0069739631999999998 * fTemp209) + ((0.14359815879999999 * fTemp100) + ((0.056070829099999997 * fTemp189) + ((0.071520838200000006 * fTemp96) + ((0.11053658969999999 * fTemp88) + ((0.059357348400000003 * fTemp81) + ((0.15802246449999999 * fTemp78) + ((0.028856797999999999 * fTemp8) + ((0.0184712442 * fTemp9) + ((0.036013441899999998 * fTemp10) + ((0.0040158106000000001 * fTemp176) + ((0.011430287799999999 * fTemp11) + ((0.0029795344 * fTemp185) + ((0.063900898100000006 * fTemp73) + ((0.024132458200000002 * fTemp65) + ((0.034600315600000001 * fTemp57) + ((0.049898880700000002 * fTemp49) + ((0.040164873500000003 * fTemp33) + (0.0295675634 * fTemp41)))))))))))))))))))))))))))))))))))));
			output3[i] = FAUSTFLOAT((fRec0[0] * (((0.0377262378 * fTemp174) + ((0.0189133823 * fTemp166) + ((0.015651603300000001 * fTemp320) + ((0.0127363497 * fTemp312) + ((0.014246322 * fTemp277) + ((0.015231990500000001 * fTemp270) + ((0.083783126200000002 * fTemp263) + ((0.0135438131 * fTemp129) + ((0.0226764055 * fTemp122) + ((0.0050681861000000002 * fTemp250) + ((0.025270647600000001 * fTemp238) + ((0.13802548680000001 * fTemp110) + ((0.12412394760000001 * fTemp214) + ((0.0193772098 * fTemp209) + ((0.077486018300000001 * fTemp204) + ((0.041472203999999999 * fTemp199) + ((0.085832604699999995 * fTemp105) + ((0.039300896500000002 * fTemp189) + ((0.1321335672 * fTemp92) + ((0.1132247168 * fTemp88) + ((0.065738699999999997 * fTemp75) + ((0.0056257242000000004 * fTemp8) + ((0.014249064800000001 * fTemp9) + ((0.045965488999999998 * fTemp10) + ((0.039639223199999997 * fTemp176) + ((0.017818624000000002 * fTemp11) + ((0.026239464699999999 * fTemp12) + ((0.039314056299999997 * fTemp13) + ((0.018454022099999998 * fTemp15) + ((0.0040972826999999996 * fTemp16) + (((0.0149243806 * fTemp184) + ((0.053109404200000002 * fTemp73) + ((0.0204742768 * fTemp65) + (((0.043434894699999997 * fTemp25) + (0.0073982335000000003 * fTemp41)) + (0.0029637501999999999 * fTemp57))))) + (0.0033683684999999998 * fTemp185)))))))))))))))))))))))))))))))) - ((0.0035236066000000001 * fTemp158) + ((0.063318738799999996 * fTemp305) + ((0.044260376599999998 * fTemp298) + ((0.0075925293999999999 * fTemp150) + ((0.036449482399999997 * fTemp143) + ((0.019286465900000001 * fTemp136) + ((0.035766883399999998 * fTemp291) + ((0.039737340900000001 * fTemp284) + ((0.096277824400000003 * fTemp256) + ((0.017553572199999999 * fTemp244) + ((0.069936272199999996 * fTemp232) + ((0.0185241352 * fTemp226) + ((0.086649944300000004 * fTemp220) + ((0.1154432755 * fTemp116) + ((0.079511970400000007 * fTemp194) + ((0.14348462919999999 * fTemp100) + ((0.063187584199999994 * fTemp96) + ((0.053262764800000001 * fTemp84) + ((0.067003978699999994 * fTemp81) + ((0.15519847740000001 * fTemp78) + ((0.0140445785 * fTemp7) + ((0.0090334062 * fTemp175) + ((0.012696724899999999 * fTemp14) + ((0.016529921 * fTemp17) + (((0.0350904197 * fTemp33) + (0.034186204800000002 * fTemp49)) + (0.021511105400000001 * fTemp74)))))))))))))))))))))))))))));
			output4[i] = FAUSTFLOAT((fRec0[0] * (((0.014533056500000001 * fTemp174) + ((0.0100778059 * fTemp166) + ((0.0039904119 * fTemp320) + ((0.012835388 * fTemp305) + ((0.027784587199999999 * fTemp298) + ((0.0461362487 * fTemp291) + ((0.0071331520999999998 * fTemp284) + ((0.0053976744999999996 * fTemp270) + ((0.014436057299999999 * fTemp256) + ((0.1051187591 * fTemp232) + ((0.092727534099999995 * fTemp220) + ((0.1042012447 * fTemp116) + ((0.024735920500000001 * fTemp209) + ((0.0527173129 * fTemp199) + ((0.15874662710000001 * fTemp100) + ((0.096082140799999993 * fTemp189) + ((0.097377326700000003 * fTemp96) + ((0.19172425870000001 * fTemp88) + ((((0.0016199526 * fTemp8) + ((0.0035290414999999999 * fTemp175) + ((0.029856167699999998 * fTemp11) + ((0.0070999475999999999 * fTemp14) + ((0.0015395074 * fTemp17) + ((0.018433007099999999 * fTemp74) + ((0.0124784197 * fTemp185) + (((0.0022936865999999998 * fTemp57) + ((0.019105965700000001 * fTemp49) + ((0.070439868000000003 * fTemp33) + (0.048457801199999997 * fTemp41)))) + (0.0051471268000000004 * fTemp184))))))))) + (0.34804018959999999 * fTemp75)) + (0.42219681100000001 * fTemp81)))))))))))))))))))) - ((0.0049613690999999998 * fTemp158) + ((0.0094861916000000008 * fTemp312) + ((0.0080934144999999999 * fTemp150) + ((0.0158931052 * fTemp143) + ((0.024868615 * fTemp136) + ((0.029315884800000001 * fTemp277) + ((0.047377041000000002 * fTemp263) + ((0.0255128232 * fTemp129) + ((0.0043896819999999998 * fTemp122) + ((0.0152199133 * fTemp250) + ((0.056267804800000001 * fTemp244) + ((0.1182518169 * fTemp238) + ((0.020432436200000001 * fTemp226) + ((0.043716579200000001 * fTemp110) + ((0.049799949699999999 * fTemp214) + ((0.1118260237 * fTemp204) + ((0.053575935700000001 * fTemp194) + ((0.1570838031 * fTemp105) + ((0.079077966700000002 * fTemp92) + ((0.175724713 * fTemp84) + (((0.029402619599999999 * fTemp7) + ((0.011827579600000001 * fTemp9) + ((0.0004607368 * fTemp10) + ((0.0033401322000000001 * fTemp176) + ((0.0085342540999999994 * fTemp12) + ((0.039723297900000003 * fTemp13) + ((0.035637466899999998 * fTemp15) + (((0.031934610500000002 * fTemp73) + ((0.085179358699999999 * fTemp25) + (0.0095895127000000004 * fTemp65))) + (0.022300504700000001 * fTemp16))))))))) + (0.20561176270000001 * fTemp78)))))))))))))))))))))))));
			output5[i] = FAUSTFLOAT((fRec0[0] * (((0.0008900437 * fTemp174) + ((0.0001670854 * fTemp320) + ((0.0061583799000000002 * fTemp312) + ((0.018655949500000001 * fTemp305) + ((0.0305228476 * fTemp298) + ((0.017314799200000001 * fTemp150) + ((0.030391935299999999 * fTemp143) + ((0.087501224099999997 * fTemp291) + ((0.030852416399999999 * fTemp277) + ((0.0058138959999999998 * fTemp270) + ((0.027729166199999999 * fTemp263) + ((0.0257388255 * fTemp129) + ((0.020878836099999999 * fTemp256) + ((0.030500629200000001 * fTemp244) + ((0.015001640300000001 * fTemp238) + ((0.060161276600000001 * fTemp209) + ((0.0146632736 * fTemp194) + ((0.15762928609999999 * fTemp105) + ((0.092037422699999996 * fTemp100) + ((0.0329606712 * fTemp189) + ((0.085281632400000001 * fTemp92) + ((0.023636591299999999 * fTemp81) + ((0.20839176549999999 * fTemp78) + ((0.1495484856 * fTemp75) + ((0.0112201405 * fTemp8) + ((0.0048041782999999998 * fTemp175) + ((0.040463587099999997 * fTemp13) + ((0.030477530999999999 * fTemp15) + ((0.022916857999999998 * fTemp16) + ((((0.015220346799999999 * fTemp57) + (((0.078286402000000005 * fTemp25) + (0.015594473899999999 * fTemp33)) + (0.035520297499999999 * fTemp49))) + (0.0154733861 * fTemp184)) + (0.0043122717000000001 * fTemp17))))))))))))))))))))))))))))))) - ((0.0033058519000000001 * fTemp166) + ((0.0068225296999999997 * fTemp158) + ((0.0123738193 * fTemp136) + ((0.012938400799999999 * fTemp284) + ((0.0058142981000000003 * fTemp122) + ((0.017876272299999999 * fTemp250) + ((0.1030790021 * fTemp232) + ((0.0054012590000000003 * fTemp226) + ((0.086373405299999997 * fTemp220) + ((0.1174312307 * fTemp116) + ((0.0521062531 * fTemp110) + ((0.1203285128 * fTemp214) + ((0.078085540300000006 * fTemp204) + ((0.045389104499999999 * fTemp199) + ((0.14477288869999999 * fTemp96) + ((0.2175610254 * fTemp88) + ((0.24493393990000001 * fTemp84) + ((0.023203920400000001 * fTemp7) + ((0.012674230700000001 * fTemp9) + ((0.021552166500000001 * fTemp10) + ((0.035040743499999999 * fTemp176) + ((0.0143502519 * fTemp11) + ((0.058177539899999998 * fTemp12) + ((0.00028738320000000001 * fTemp14) + ((0.0228208352 * fTemp74) + (((0.023839016000000001 * fTemp73) + ((0.0244278881 * fTemp41) + (0.0041012000000000002 * fTemp65))) + (0.0121523373 * fTemp185))))))))))))))))))))))))))))));
			output6[i] = FAUSTFLOAT((fRec0[0] * (((0.0034122798000000001 * fTemp158) + ((0.039879849199999998 * fTemp284) + ((0.022937254099999999 * fTemp122) + ((0.0051420570000000002 * fTemp250) + ((0.025383191100000001 * fTemp238) + ((0.069935677799999998 * fTemp232) + ((0.0186102509 * fTemp226) + ((0.086859255900000001 * fTemp220) + ((0.1152047596 * fTemp116) + ((0.13794700090000001 * fTemp110) + ((0.12424993469999999 * fTemp214) + ((0.019422567200000001 * fTemp209) + ((0.077515289700000004 * fTemp204) + ((0.079389760500000003 * fTemp194) + ((0.039271934299999998 * fTemp189) + ((0.15544078859999999 * fTemp78) + ((0.065842443700000003 * fTemp75) + ((0.0060904011999999997 * fTemp8) + ((0.014341205399999999 * fTemp9) + ((0.046021126500000002 * fTemp10) + ((0.039656927799999998 * fTemp176) + ((0.017843053399999999 * fTemp11) + ((0.0261473435 * fTemp12) + ((0.012525164300000001 * fTemp14) + ((0.016694614100000001 * fTemp17) + ((0.021381395000000001 * fTemp74) + ((0.014338771700000001 * fTemp184) + ((0.052872500599999997 * fTemp73) + ((0.020574898500000001 * fTemp65) + ((0.0072913593000000004 * fTemp41) + (0.0028093034000000001 * fTemp57))))))))))))))))))))))))))))))) - ((0.037840283000000002 * fTemp174) + ((0.0190262795 * fTemp166) + ((0.016099378800000001 * fTemp320) + ((0.0126665083 * fTemp312) + ((0.063057113200000001 * fTemp305) + ((0.0446013876 * fTemp298) + ((0.0077028959000000003 * fTemp150) + ((0.036496412899999997 * fTemp143) + ((0.019373777799999999 * fTemp136) + ((0.035699736400000001 * fTemp291) + ((0.014057068000000001 * fTemp277) + ((0.0152478873 * fTemp270) + ((0.083497642100000005 * fTemp263) + ((0.013088802300000001 * fTemp129) + ((0.096042956999999998 * fTemp256) + ((0.0174423693 * fTemp244) + ((0.0416249988 * fTemp199) + ((0.086006297300000006 * fTemp105) + ((0.14369428000000001 * fTemp100) + ((0.063336491600000003 * fTemp96) + ((0.13223388790000001 * fTemp92) + ((0.1132727083 * fTemp88) + ((0.053315518499999999 * fTemp84) + ((0.067057208899999998 * fTemp81) + ((0.0138275793 * fTemp7) + ((0.0089439728999999996 * fTemp175) + ((0.039424575199999999 * fTemp13) + ((0.018487706199999999 * fTemp15) + ((0.0041420607999999998 * fTemp16) + ((((0.043362361299999999 * fTemp25) + (0.035211708500000001 * fTemp33)) + (0.034261809099999999 * fTemp49)) + (0.0038498745999999999 * fTemp185))))))))))))))))))))))))))))))))));
			output7[i] = FAUSTFLOAT((fRec0[0] * (((0.0229755993 * fTemp174) + ((0.017768743600000001 * fTemp166) + ((0.041862682599999999 * fTemp320) + ((0.014951366400000001 * fTemp312) + ((0.059910982699999997 * fTemp305) + ((0.022351459899999999 * fTemp298) + ((0.0075258199999999999 * fTemp136) + ((0.053516991700000002 * fTemp284) + ((0.045188762200000003 * fTemp277) + ((0.023768001399999999 * fTemp270) + ((0.1140747134 * fTemp263) + ((0.014395310099999999 * fTemp122) + ((0.1372690017 * fTemp256) + ((0.0325693393 * fTemp250) + ((0.036417188099999998 * fTemp244) + ((0.035466187099999998 * fTemp238) + ((0.043659735599999999 * fTemp232) + ((0.0063883812999999999 * fTemp226) + ((0.028026695000000001 * fTemp220) + ((0.084009779699999995 * fTemp214) + ((0.062565539599999997 * fTemp204) + ((0.1106855288 * fTemp88) + ((0.053347341499999999 * fTemp84) + ((0.15768411830000001 * fTemp78) + ((0.066701667399999998 * fTemp75) + ((0.0067654302000000003 * fTemp7) + ((0.013316581900000001 * fTemp175) + ((0.0026261561999999998 * fTemp12) + ((0.0237663145 * fTemp184) + (0.0032030255000000001 * fTemp185)))))))))))))))))))))))))))))) - ((0.021684952899999999 * fTemp158) + ((0.019775048199999999 * fTemp150) + ((0.0030992963000000002 * fTemp143) + ((0.016494173899999999 * fTemp291) + ((0.023154547500000001 * fTemp129) + ((0.10880103939999999 * fTemp116) + ((0.13212661219999999 * fTemp110) + ((0.0070182964000000004 * fTemp209) + ((0.059048910500000003 * fTemp199) + ((0.1145955126 * fTemp194) + ((0.081093919400000006 * fTemp105) + ((0.14323827289999999 * fTemp100) + ((0.0560820234 * fTemp189) + ((0.071382771600000006 * fTemp96) + ((0.1099681072 * fTemp92) + ((0.059187950599999997 * fTemp81) + ((0.0292485959 * fTemp8) + ((0.018564838600000001 * fTemp9) + ((0.036234389700000001 * fTemp10) + ((0.0042536852000000002 * fTemp176) + ((0.0114331624 * fTemp11) + ((0.045066360999999999 * fTemp13) + ((0.051253883700000002 * fTemp14) + ((0.0347159431 * fTemp15) + ((0.018102393000000001 * fTemp16) + ((0.023304824799999999 * fTemp17) + (((0.064009328899999995 * fTemp73) + ((0.0243179811 * fTemp65) + ((0.034534241100000002 * fTemp57) + ((0.049818739700000003 * fTemp49) + ((0.0295427669 * fTemp41) + ((0.0096600643999999996 * fTemp25) + (0.040004995799999998 * fTemp33))))))) + (0.0175414786 * fTemp74)))))))))))))))))))))))))))))));
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec70[1] = fRec70[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec72[1] = fRec72[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec108[1] = fRec108[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec127[1] = fRec127[0];
			fRec125[1] = fRec125[0];
			fRec124[1] = fRec124[0];
			fRec122[1] = fRec122[0];
			fRec121[1] = fRec121[0];
			fRec119[1] = fRec119[0];
			fRec118[1] = fRec118[0];
			fRec116[1] = fRec116[0];
			fRec115[1] = fRec115[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec110[1] = fRec110[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec128[2] = fRec128[1];
			fRec128[1] = fRec128[0];
			fRec147[2] = fRec147[1];
			fRec147[1] = fRec147[0];
			fRec148[2] = fRec148[1];
			fRec148[1] = fRec148[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[2] = fRec149[1];
			fRec149[1] = fRec149[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec153[2] = fRec153[1];
			fRec153[1] = fRec153[0];
			fRec160[1] = fRec160[0];
			fRec158[1] = fRec158[0];
			fRec157[2] = fRec157[1];
			fRec157[1] = fRec157[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[2] = fRec161[1];
			fRec161[1] = fRec161[0];
			fRec174[1] = fRec174[0];
			fRec172[1] = fRec172[0];
			fRec171[1] = fRec171[0];
			fRec169[1] = fRec169[0];
			fRec168[2] = fRec168[1];
			fRec168[1] = fRec168[0];
			fRec181[1] = fRec181[0];
			fRec179[1] = fRec179[0];
			fRec178[1] = fRec178[0];
			fRec176[1] = fRec176[0];
			fRec175[2] = fRec175[1];
			fRec175[1] = fRec175[0];
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec182[2] = fRec182[1];
			fRec182[1] = fRec182[0];
			fRec198[1] = fRec198[0];
			fRec196[1] = fRec196[0];
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec192[1] = fRec192[0];
			fRec190[1] = fRec190[0];
			fRec189[2] = fRec189[1];
			fRec189[1] = fRec189[0];
			fRec208[1] = fRec208[0];
			fRec206[1] = fRec206[0];
			fRec205[1] = fRec205[0];
			fRec203[1] = fRec203[0];
			fRec202[1] = fRec202[0];
			fRec200[1] = fRec200[0];
			fRec199[2] = fRec199[1];
			fRec199[1] = fRec199[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec209[2] = fRec209[1];
			fRec209[1] = fRec209[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[2] = fRec222[1];
			fRec222[1] = fRec222[0];
			fRec250[1] = fRec250[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec245[1] = fRec245[0];
			fRec244[1] = fRec244[0];
			fRec242[1] = fRec242[0];
			fRec241[1] = fRec241[0];
			fRec239[1] = fRec239[0];
			fRec238[1] = fRec238[0];
			fRec236[1] = fRec236[0];
			fRec235[2] = fRec235[1];
			fRec235[1] = fRec235[0];
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[2] = fRec251[1];
			fRec251[1] = fRec251[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec267[2] = fRec267[1];
			fRec267[1] = fRec267[0];
			fRec298[1] = fRec298[0];
			fRec296[1] = fRec296[0];
			fRec295[1] = fRec295[0];
			fRec293[1] = fRec293[0];
			fRec292[1] = fRec292[0];
			fRec290[1] = fRec290[0];
			fRec289[1] = fRec289[0];
			fRec287[1] = fRec287[0];
			fRec286[1] = fRec286[0];
			fRec284[1] = fRec284[0];
			fRec283[2] = fRec283[1];
			fRec283[1] = fRec283[0];
			fRec317[1] = fRec317[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec312[1] = fRec312[0];
			fRec311[1] = fRec311[0];
			fRec309[1] = fRec309[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[2] = fRec299[1];
			fRec299[1] = fRec299[0];
			fRec336[1] = fRec336[0];
			fRec334[1] = fRec334[0];
			fRec333[1] = fRec333[0];
			fRec331[1] = fRec331[0];
			fRec330[1] = fRec330[0];
			fRec328[1] = fRec328[0];
			fRec327[1] = fRec327[0];
			fRec325[1] = fRec325[0];
			fRec324[1] = fRec324[0];
			fRec322[1] = fRec322[0];
			fRec321[1] = fRec321[0];
			fRec319[1] = fRec319[0];
			fRec318[2] = fRec318[1];
			fRec318[1] = fRec318[0];
			fRec355[1] = fRec355[0];
			fRec353[1] = fRec353[0];
			fRec352[1] = fRec352[0];
			fRec350[1] = fRec350[0];
			fRec349[1] = fRec349[0];
			fRec347[1] = fRec347[0];
			fRec346[1] = fRec346[0];
			fRec344[1] = fRec344[0];
			fRec343[1] = fRec343[0];
			fRec341[1] = fRec341[0];
			fRec340[1] = fRec340[0];
			fRec338[1] = fRec338[0];
			fRec337[2] = fRec337[1];
			fRec337[1] = fRec337[0];
			fRec356[2] = fRec356[1];
			fRec356[1] = fRec356[0];
			fRec357[2] = fRec357[1];
			fRec357[1] = fRec357[0];
			fRec376[1] = fRec376[0];
			fRec374[1] = fRec374[0];
			fRec373[1] = fRec373[0];
			fRec371[1] = fRec371[0];
			fRec370[1] = fRec370[0];
			fRec368[1] = fRec368[0];
			fRec367[1] = fRec367[0];
			fRec365[1] = fRec365[0];
			fRec364[1] = fRec364[0];
			fRec362[1] = fRec362[0];
			fRec361[1] = fRec361[0];
			fRec359[1] = fRec359[0];
			fRec358[2] = fRec358[1];
			fRec358[1] = fRec358[0];
			fRec377[2] = fRec377[1];
			fRec377[1] = fRec377[0];
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec381[1] = fRec381[0];
			fRec379[1] = fRec379[0];
			fRec378[2] = fRec378[1];
			fRec378[1] = fRec378[0];
			fRec394[1] = fRec394[0];
			fRec392[1] = fRec392[0];
			fRec391[1] = fRec391[0];
			fRec389[1] = fRec389[0];
			fRec388[1] = fRec388[0];
			fRec386[1] = fRec386[0];
			fRec385[2] = fRec385[1];
			fRec385[1] = fRec385[0];
			fRec404[1] = fRec404[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec399[1] = fRec399[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[2] = fRec395[1];
			fRec395[1] = fRec395[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec405[2] = fRec405[1];
			fRec405[1] = fRec405[0];
			fRec424[1] = fRec424[0];
			fRec422[1] = fRec422[0];
			fRec421[1] = fRec421[0];
			fRec419[1] = fRec419[0];
			fRec418[1] = fRec418[0];
			fRec416[1] = fRec416[0];
			fRec415[2] = fRec415[1];
			fRec415[1] = fRec415[0];
			fRec434[1] = fRec434[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec429[1] = fRec429[0];
			fRec428[1] = fRec428[0];
			fRec426[1] = fRec426[0];
			fRec425[2] = fRec425[1];
			fRec425[1] = fRec425[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[2] = fRec435[1];
			fRec435[1] = fRec435[0];
			fRec460[1] = fRec460[0];
			fRec458[1] = fRec458[0];
			fRec457[1] = fRec457[0];
			fRec455[1] = fRec455[0];
			fRec454[1] = fRec454[0];
			fRec452[1] = fRec452[0];
			fRec451[1] = fRec451[0];
			fRec449[1] = fRec449[0];
			fRec448[2] = fRec448[1];
			fRec448[1] = fRec448[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec467[1] = fRec467[0];
			fRec465[1] = fRec465[0];
			fRec464[1] = fRec464[0];
			fRec462[1] = fRec462[0];
			fRec461[2] = fRec461[1];
			fRec461[1] = fRec461[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
			fRec474[2] = fRec474[1];
			fRec474[1] = fRec474[0];
			fRec499[1] = fRec499[0];
			fRec497[1] = fRec497[0];
			fRec496[1] = fRec496[0];
			fRec494[1] = fRec494[0];
			fRec493[1] = fRec493[0];
			fRec491[1] = fRec491[0];
			fRec490[1] = fRec490[0];
			fRec488[1] = fRec488[0];
			fRec487[2] = fRec487[1];
			fRec487[1] = fRec487[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec503[1] = fRec503[0];
			fRec501[1] = fRec501[0];
			fRec500[2] = fRec500[1];
			fRec500[1] = fRec500[0];
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec522[1] = fRec522[0];
			fRec520[1] = fRec520[0];
			fRec519[1] = fRec519[0];
			fRec517[1] = fRec517[0];
			fRec516[1] = fRec516[0];
			fRec514[1] = fRec514[0];
			fRec513[2] = fRec513[1];
			fRec513[1] = fRec513[0];
			fRec541[1] = fRec541[0];
			fRec539[1] = fRec539[0];
			fRec538[1] = fRec538[0];
			fRec536[1] = fRec536[0];
			fRec535[1] = fRec535[0];
			fRec533[1] = fRec533[0];
			fRec532[1] = fRec532[0];
			fRec530[1] = fRec530[0];
			fRec529[1] = fRec529[0];
			fRec527[1] = fRec527[0];
			fRec526[2] = fRec526[1];
			fRec526[1] = fRec526[0];
			fRec557[1] = fRec557[0];
			fRec555[1] = fRec555[0];
			fRec554[1] = fRec554[0];
			fRec552[1] = fRec552[0];
			fRec551[1] = fRec551[0];
			fRec549[1] = fRec549[0];
			fRec548[1] = fRec548[0];
			fRec546[1] = fRec546[0];
			fRec545[1] = fRec545[0];
			fRec543[1] = fRec543[0];
			fRec542[2] = fRec542[1];
			fRec542[1] = fRec542[0];
			fRec573[1] = fRec573[0];
			fRec571[1] = fRec571[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec558[2] = fRec558[1];
			fRec558[1] = fRec558[0];
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
			fRec574[2] = fRec574[1];
			fRec574[1] = fRec574[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec590[2] = fRec590[1];
			fRec590[1] = fRec590[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[2] = fRec606[1];
			fRec606[1] = fRec606[0];
			fRec637[1] = fRec637[0];
			fRec635[1] = fRec635[0];
			fRec634[1] = fRec634[0];
			fRec632[1] = fRec632[0];
			fRec631[1] = fRec631[0];
			fRec629[1] = fRec629[0];
			fRec628[1] = fRec628[0];
			fRec626[1] = fRec626[0];
			fRec625[1] = fRec625[0];
			fRec623[1] = fRec623[0];
			fRec622[2] = fRec622[1];
			fRec622[1] = fRec622[0];
			fRec656[1] = fRec656[0];
			fRec654[1] = fRec654[0];
			fRec653[1] = fRec653[0];
			fRec651[1] = fRec651[0];
			fRec650[1] = fRec650[0];
			fRec648[1] = fRec648[0];
			fRec647[1] = fRec647[0];
			fRec645[1] = fRec645[0];
			fRec644[1] = fRec644[0];
			fRec642[1] = fRec642[0];
			fRec641[1] = fRec641[0];
			fRec639[1] = fRec639[0];
			fRec638[2] = fRec638[1];
			fRec638[1] = fRec638[0];
			fRec675[1] = fRec675[0];
			fRec673[1] = fRec673[0];
			fRec672[1] = fRec672[0];
			fRec670[1] = fRec670[0];
			fRec669[1] = fRec669[0];
			fRec667[1] = fRec667[0];
			fRec666[1] = fRec666[0];
			fRec664[1] = fRec664[0];
			fRec663[1] = fRec663[0];
			fRec661[1] = fRec661[0];
			fRec660[1] = fRec660[0];
			fRec658[1] = fRec658[0];
			fRec657[2] = fRec657[1];
			fRec657[1] = fRec657[0];
			
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
