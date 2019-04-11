TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
#  Optimization of db files using dbst (DEFAULT: NO)
#DB_OPT = YES

ifdef MOTOR_PIGCS2
### this module was built outside motor
DB_INSTALLS += $(MOTOR_PIGCS2)/db/PI_SupportCtrl.db
DB_INSTALLS += $(MOTOR_PIGCS2)/db/PI_Support.db
else
### this module was built inside motor/modules
DB_INSTALLS += $(MOTOR)/db/PI_SupportCtrl.db
DB_INSTALLS += $(MOTOR)/db/PI_Support.db
endif

#----------------------------------------------------
# Create and install (or just install) into <top>/db
# databases, templates, substitutions like this
#DB += xxx.db

#----------------------------------------------------
# If <anyname>.db template is not named <anyname>*.template add
# <anyname>_template = <templatename>

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

