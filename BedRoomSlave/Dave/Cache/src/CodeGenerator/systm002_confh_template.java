package CodeGenerator;

import java.util.*;
import java.text.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class systm002_confh_template
{
  protected static String nl;
  public static synchronized systm002_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    systm002_confh_template result = new systm002_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*******************************************************************************" + NL + "**                                                                            **" + NL + "** Copyright (C) 2014 Infineon Technologies AG. All rights reserved.          **" + NL + "**                                                                            **" + NL + "** Infineon Technologies AG (Infineon) is supplying this software for use     **" + NL + "** with Infineon's microcontrollers.                                          **" + NL + "** This file can be freely distributed within development tools that are      **" + NL + "** supporting such microcontrollers.                                          **" + NL + "**                                                                            **" + NL + "** THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS,        **" + NL + "** IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES    **" + NL + "** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS      **" + NL + "** SOFTWARE. INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, **" + NL + "** INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.           **" + NL + "**                                                                            **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC1000/XMC4000 Series                                 **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR   : App Developer                                                   **" + NL + "**                                                                            **" + NL + "** NOTE     : Any Changes made to this file will be overwritten during Code   **" + NL + "**            Generation                                                      **" + NL + "**                                                                            **" + NL + "********************************************************************************" + NL + "** VERSION HISTORY:" + NL + "********************************************************************************" + NL + "** v1.0.0, 25 Sep 2013,  SSS: Initial version for XMC1000/XMC4000 series." + NL + "** v1.0.2  10 Oct 2013,  SSS: 1.C++ codebase support is added." + NL + "**                            2.macros are renamed " + NL + "**                               a. PRIORITY to SYSTM002_PRIORITY" + NL + "**                               b. SUBPRIORITY to SYSTM002_SUBPRIORITY" + NL + "**                            3.Variable systick is renamed as SYSTM002_Systick" + NL + "**" + NL + "** v1.0.6  29 Jan 2014,  SSM: 1. DBG002 App changes are taken care." + NL + "**                             " + NL + "** V1.0.8  06 Feb 2014,     : 1. XMC1000 VQFN package support added;   " + NL + "**                         XMC4000 Device support extended for XMC4500 AC step," + NL + "**                                XMC4400 AB Step and XMC4200 AB Step. " + NL + "**" + NL + "** V1.0.10 25 Feb 2014,  SSM: 1. Floating point multiplication and Division     " + NL + "**                                  inside API are removed. " + NL + "**                            2. SYSTM002_GetSysTickCount(uint32_t Period)API " + NL + "**                                removed and it is replaced with the macro" + NL + "**                                 SYSTM002_SysTickMicroSec(microsec)" + NL + "**" + NL + "** V1.0.12 23 Apr 2014,  SSM: 1. Fixes Floating operation issue " + NL + "**                                in XMC4x series." + NL + "**" + NL + "*******************************************************************************/" + NL + "" + NL + "/**" + NL + " * @file SYSTM002_Conf.h" + NL + " *" + NL + " * @brief This file contains extern declarations and global macro definitions " + NL + " * of SYSTM002." + NL + " *" + NL + " */" + NL + "" + NL + "#ifndef SYSTM002_CONF_H_" + NL + "#define SYSTM002_CONF_H_" + NL + "" + NL + "/* Support for C++ codebase */" + NL + "#ifdef __cplusplus" + NL + "extern \"C\" {" + NL + "#endif" + NL + "/*******************************************************************************" + NL + "** INCLUDE FILES:" + NL + "*******************************************************************************/";
  protected final String TEXT_2 = NL + "#include \"../../inc/DBG002/DBG002.h\"";
  protected final String TEXT_3 = NL + NL + NL + "/*******************************************************************************" + NL + "** GLOBAL MACRO DEFINITIONS:                   " + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @ingroup SYSTM002_constants" + NL + " * @{" + NL + " */";
  protected final String TEXT_4 = NL + "/* Priority group */";
  protected final String TEXT_5 = NL + "#define SYSTM002_PRIORITY     ";
  protected final String TEXT_6 = "U" + NL + "#define SYSTM002_SUBPRIORITY  ";
  protected final String TEXT_7 = "U";
  protected final String TEXT_8 = NL + "#define SYSTM002_PRIORITY ";
  protected final String TEXT_9 = "U";
  protected final String TEXT_10 = NL + NL + "/* System Core clock frequency in Hz multiplied by 1000000" + NL + "*  changes has done to avoid Float operation" + NL + "*/";
  protected final String TEXT_11 = NL + "#define SYSTM002_SYS_CORE_CLOCK  ";
  protected final String TEXT_12 = "U";
  protected final String TEXT_13 = NL + "#define SYSTM002_SYS_CORE_CLOCK  ";
  protected final String TEXT_14 = "U";
  protected final String TEXT_15 = NL + NL + "/* Time between two systick interrupt in usec */";
  protected final String TEXT_16 = NL + "#define SYSTM002_SYSTICK_INTERVAL ";
  protected final String TEXT_17 = "U";
  protected final String TEXT_18 = NL + "#define SYSTM002_SYSTICK_INTERVAL 10U";
  protected final String TEXT_19 = NL + "/* Maximum Number of timer */" + NL + "#define SYSTM002_CFG_MAX_TMR  ";
  protected final String TEXT_20 = "U " + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "** GLOBAL TYPE DEFINITIONS:                     " + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "** GLOBAL VARIABLE DEFINITIONS: " + NL + "*******************************************************************************/" + NL + "" + NL + "/*******************************************************************************" + NL + "** FUNCTION PROTOTYPES:" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @ingroup SYSTM002_apidoc" + NL + " * @{" + NL + " */" + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + "** ENUMERATIONS:" + NL + "*******************************************************************************/" + NL + "/**" + NL + "  * @ingroup SYSTM002_publicparam" + NL + "  * @{" + NL + "  */" + NL + "" + NL + "/**" + NL + " * @}" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + "** STRUCTURES:" + NL + "*******************************************************************************/" + NL + "" + NL + "/* Support for C++ codebase */" + NL + "#ifdef __cplusplus" + NL + "}" + NL + "#endif   " + NL + "" + NL + "#endif /* SYSTM002_CONF_H_ */" + NL + "" + NL + "/*CODE_BLOCK_END*/" + NL;
  protected final String TEXT_21 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     String AppBaseuri = "app/systm002/0";
    stringBuffer.append(TEXT_1);
     String TempApps = null;
   String MyAppName = null;
   ArrayList<String> apps;
   String TempLowerApps = null; 
   boolean DBGApp = false;   
   apps=(ArrayList<String>)(app.getApps());
        for (int k = 0; k < apps.size(); k++) {
              TempApps = apps.get(k);
              MyAppName = TempApps.substring(TempApps.indexOf("/app/") + 5, TempApps.lastIndexOf("/"));
              TempLowerApps = MyAppName.toLowerCase();
              if (TempLowerApps.equalsIgnoreCase("dbg002")) {DBGApp = true;}   
  } 
     if(DBGApp) { 
    stringBuffer.append(TEXT_2);
     } 
    stringBuffer.append(TEXT_3);
    int XMC1xxx=-1;
     double temp1 = 0.0; 
    XMC1xxx=app.getSoftwareId().substring(0,1).compareTo("1");
    stringBuffer.append(TEXT_4);
    if(XMC1xxx!=0)
    {
    stringBuffer.append(TEXT_5);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + "/systm002_irwInterruptPriority") );
    stringBuffer.append(TEXT_6);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + "/systm002_irwInterruptSubPriority") );
    stringBuffer.append(TEXT_7);
    }
    else {
    stringBuffer.append(TEXT_8);
    stringBuffer.append( app.getIntegerValue(AppBaseuri + "/systm002_irwInterruptPrio_timm") );
    stringBuffer.append(TEXT_9);
    }
    stringBuffer.append(TEXT_10);
    if(XMC1xxx!=0)
    {
    stringBuffer.append(TEXT_11);
    stringBuffer.append( app.getIntegerValue (AppBaseuri + "/clkapp/clk001_iroActualFreqSystem" ) *  1000000 );
    stringBuffer.append(TEXT_12);
    }
    else {
     temp1 = (app.getDoubleValue (AppBaseuri + "/clockapp/clk002_irMCLK" ) * 1000000); 
    stringBuffer.append(TEXT_13);
    stringBuffer.append( Math.round(temp1) );
    stringBuffer.append(TEXT_14);
    }
    stringBuffer.append(TEXT_15);
    int SYSTM002_Systick = app.getIntegerValue (AppBaseuri + "/systm002_systickinterval" );
if(SYSTM002_Systick > 0) {
    stringBuffer.append(TEXT_16);
    stringBuffer.append(SYSTM002_Systick);
    stringBuffer.append(TEXT_17);
    }else {
    stringBuffer.append(TEXT_18);
    }
    stringBuffer.append(TEXT_19);
    stringBuffer.append( app.getIntegerValue (AppBaseuri + "/systm002_swtimers" ));
    stringBuffer.append(TEXT_20);
    stringBuffer.append(TEXT_21);
    return stringBuffer.toString();
  }
}
