/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     V_INTEGER = 258,
     V_FLOAT = 259,
     V_CHAR = 260,
     INT = 261,
     CHAR = 262,
     NATURAL = 263,
     FLOAT = 264,
     POSITIVE = 265,
     STRING = 266,
     BOOLEAN = 267,
     ADD = 268,
     RELATION_EXP = 269,
     EQUALITY_EXP = 270,
     PROCEDURE = 271,
     DESCONOCIDO = 272,
     NOMBRE = 273,
     PCOMA = 274,
     PUTLINE = 275,
     RETURN = 276,
     IF = 277,
     DELIMITADORES = 278,
     COMILLA = 279,
     COMA = 280,
     PIGUAL = 281,
     INCR = 282,
     MULT = 283,
     DIVISION = 284,
     FOR = 285,
     LOOP = 286,
     IN = 287,
     END = 288,
     MAIN = 289,
     IS = 290,
     DOSPUNTOS = 291,
     ELSE = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 22 "archivo_bison.y"

	int ival;
	float fval;
	char type[10];
	char name[20];
	char *sval;
	char cval;

	struct Nodo_AST * nodo;
	union Tipo_Valor * value_type;
	int data_type;



/* Line 1685 of yacc.c  */
#line 103 "archivo_bison.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


