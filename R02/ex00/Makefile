# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svidot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 08:34:00 by svidot            #+#    #+#              #
#    Updated: 2023/07/30 20:17:32 by smarty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c aff.c array_manager.c array_manage_2.c make_tab.c
OBJ_FILES = $(SRC_FILES:.c=.o)
TARGET = rush02
all : $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)
clean:
	rm -f $(OBJ_FILES) $(TARGET) 
