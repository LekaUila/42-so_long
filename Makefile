# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 11:10:23 by lflandri          #+#    #+#              #
#    Updated: 2022/11/15 14:24:37 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= so_long
NAMEL		= ./LIBFT/libft.a
NAMEMLX		= ./minilibx-linux/libmlx_Linux.a
MAKEFLAGS	= --no-print-directory

ifndef BONUS
SRC 		=	mandatory/main.c\
				mandatory/parser.c\
				mandatory/free_and_cie.c\
				mandatory/free_and_cie_the_return.c\
				mandatory/map_checker.c\
				mandatory/ft_check_caractere.c\
				mandatory/ft_border_map_checker.c\
				mandatory/coor_untils.c\
				mandatory/ft_check_path_to.c\
				mandatory/ft_check_path_to_untils.c\
				mandatory/untils.c\
				mandatory/ft_make_listcase.c\
				mandatory/ft_affichemap.c\
				mandatory/check_wall_1.c\
				mandatory/ft_check_r_c_water.c\
				mandatory/ft_check_b_water.c\
				mandatory/ft_check_c_water.c\
				mandatory/create_border.c\
				mandatory/ft_create_water_fall.c\
				mandatory/ifisnotawall.c\
				mandatory/hook_file.c\
				mandatory/mc_move.c\
				mandatory/ft_check_creation.c
endif

ifdef BONUS
SRC 		=	bonus/main_bonus.c\
				bonus/parser_bonus.c\
				bonus/free_and_cie_bonus.c\
				bonus/free_and_cie_the_return_bonus.c\
				bonus/map_checker_bonus.c\
				bonus/ft_check_caractere_bonus.c\
				bonus/ft_border_map_checker_bonus.c\
				bonus/coor_untils_bonus.c\
				bonus/ft_check_path_to_bonus.c\
				bonus/ft_check_path_to_untils_bonus.c\
				bonus/untils_bonus.c\
				bonus/ft_make_listcase_bonus.c\
				bonus/ft_affichemap_bonus.c\
				bonus/check_wall_1_bonus.c\
				bonus/ft_check_r_c_water_bonus.c\
				bonus/ft_check_b_water_bonus.c\
				bonus/ft_check_c_water_bonus.c\
				bonus/create_border_bonus.c\
				bonus/ft_create_water_fall_bonus.c\
				bonus/ifisnotawall_bonus.c\
				bonus/hook_file_bonus.c\
				bonus/mc_move_bonus.c\
				bonus/ft_check_creation_bonus.c\
				bonus/ft_check_ennemis_bonus.c\
				bonus/ft_create_case_ennemis.c\
				bonus/ft_ennemis_move.c\
				bonus/count_file.c\
				bonus/end_message.c
endif

#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[;1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

all :		
			@echo -n "${BLACKCYAN}"
			@echo " ..######...#######.................##........#######..##....##..######.. ";
			@echo " .##....##.##.....##................##.......##.....##.###...##.##....##. ";
			@echo " .##.......##.....##................##.......##.....##.####..##.##....... ";
			@echo " ..######..##.....##................##.......##.....##.##.##.##.##...#### ";
			@echo " .......##.##.....##................##.......##.....##.##..####.##....##. ";
			@echo " .##....##.##.....##................##.......##.....##.##...###.##....##. ";
			@echo " ..######...#######.................########..#######..##....##..######.. ";
			@echo "${NEUTRE}"
			@make ${NAME}
			@echo "${WHITEGREEN}PROGRAMME \"${NAME}\" PRET POUR EXECUTION !${NEUTRE}"

${NAMEL}:
			@cd LIBFT && make

${NAMEMLX}:
			@echo "${BLACKPURPLE}=============== CRÉATION MINILIBX ============${WHITE}" 
			@cd minilibx-linux && make
			@echo "${BLACKPURPLE}============= FIN CRÉATION MINILIBX ==========${NEUTRE}" 
			@echo "${WHITEGREEN}Bibliotheque \"libmlx_Linux.a\" PRET À L'EMPLOIE !${NEUTRE}"

${NAME}: ${NAMEL} ${SRC} ${NAMEMLX}
			@echo "${BLACKPURPLE}=============== CRÉATION SO LONG =============${WHITE}" 
			gcc  -Wall -Wextra -Werror -g ${SRC} -Lminilibx-linux -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz ${NAMEL} ${NAMEMLX} -o ${NAME}
			@echo "${BLACKPURPLE}============= FIN CRÉATION SO LONG ===========${NEUTRE}" 

clean :
			@echo -n "${BLACKRED}"
			rm -f ${PO}
			@echo -n "${NEUTRE}"
			@cd LIBFT && make clean

fclean :	clean
			@cd minilibx-linux && make clean
			@cd LIBFT && make fclean
			@echo -n "${BLACKRED}"
			rm -f ${NAME}
			@echo -n "${NEUTRE}"

bonus :

			@echo -n "${BLACKRED}"
			@echo " .########.........#######........##....##.......##.....##........######. ";
			@echo -n "${ORANGE}"
			@echo " .##.....##.......##.....##.......###...##.......##.....##.......##....## ";
			@echo -n "${BLACKRED}"
			@echo " .##.....##.......##.....##.......####..##.......##.....##.......##...... ";
			@echo -n "${ORANGE}"
			@echo " .########........##.....##.......##.##.##.......##.....##........######. ";
			@echo -n "${BLACKRED}"
			@echo " .##.....##.......##.....##.......##..####.......##.....##.............## ";
			@echo -n "${ORANGE}"
			@echo " .##.....##.......##.....##.......##...###.......##.....##.......##....## ";
			@echo -n "${BLACKRED}"
			@echo " .########.........#######........##....##........#######.........######. ";
			@echo -n "${NEUTRE}"
			@make BONUS=42
			@echo " 💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢"
			@echo -n "${BLACKRED}"
			@echo " 💢.########.........#######........##..${ORANGE}..##.......##.....##........######.💢 ";
			@echo -n "${ORANGE}"
			@echo " 💢.##.....##.......##.....##.......###.${BLACKRED}..##.......##.....##.......##....##💢 ";
			@echo -n "${BLACKRED}"
			@echo " 💢.##.....##.......##.....##.......####${ORANGE}..##.......##.....##.......##......💢 ";
			@echo -n "${ORANGE}"
			@echo " 💢.########........##.....##.......##.#${BLACKRED}#.##.......##.....##........######.💢 ";
			@echo -n "${BLACKRED}"
			@echo " 💢.##.....##.......##.....##.......##..${ORANGE}####.......##.....##.............##💢 ";
			@echo -n "${ORANGE}"
			@echo " 💢.##.....##.......##.....##.......##..${BLACKRED}.###.......##.....##.......##....##💢 ";
			@echo -n "${BLACKRED}"
			@echo " 💢.########.........#######........##..${ORANGE}..##........#######.........######.💢 ";
			@echo -n "${NEUTRE}"
			@echo " 💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢💢"
			
re :		fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus