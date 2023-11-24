################################
######     Variables     #######
################################

NAME:=array

CC:=g++
CXXFLAGS= -std=c++98 -pedantic -Wall -Wextra -Werror -MMD -MP -O2
LDFLAGS= -std=c++98 -pedantic
ifdef FSANITIZE
	CXXFLAGS+= -g3 -fsanitize=address -DDEBUG=1
	LDFLAGS+= -g3 -fsanitize=address
endif

###################################
######     Source files     #######
###################################

# To add souce files, create a varaible for each folder, and then
# contatenate them in the SRC variable like this:

MAIN_SRC:= \
	Fixed.cpp \
	main.cpp
SRC:= $(MAIN_SRC)

####################################
######     Library files     #######
####################################

# To compile a library, store a variable for their library file like this
# and add a rule for it after the main rules:
# LIBRARY_NAME=lib/LIBRARY_NAME/LIBRARY_NAME.a

# To add a library, add the library header file like this:
# INCLUDE_DIR+= lib/LIBRARY_NAME/include

# Then add the library to the linking process in one of the following ways:
# LDFLAGS+= -Llib/LIBRARY_NAME -lLIBRARY_NAME
# LDFLAGS+= lib/LIBRARY_NAME/libLIBRARY_NAME.a

###########################################
######     Object name reformat     #######
###########################################

# This in effect makes all the object files to be compiled in the OBJ_DIR directory

SRC_DIR:=.
OBJ_DIR:=obj
OBJ:=$(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.cpp=.o)))
DEPENDS:=$(OBJ:.o=.d)

#################################
######     Main rules     #######
#################################

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) && echo "Compilation of $(NAME) successful"

##########################################
######     Library compilation     #######
##########################################

# To compile a library, add a rule like this:

# $(LIBRARY_NAME):
# 	@${MAKE} $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/LIBRARY_NAME

#########################################
######     Object compilation     #######
#########################################

-include $(DEPENDS)

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).cpp
	@$(CC) $(CXXFLAGS) $(addprefix -iquote ,$(INCLUDE_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################
######     Cleaning     #######
###############################

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re