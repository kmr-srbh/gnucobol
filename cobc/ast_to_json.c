#include "ast_to_json.h"
#include <stdio.h>

static int depth = 0;

void output_cb_tag(FILE *jsonfile, enum cb_tag tag) {
  char *tag_string;

  switch (tag) {
  case CB_TAG_CONST:
    tag_string = "CB_TAG_CONST";
    break;
  case CB_TAG_INTEGER:
    tag_string = "CB_TAG_INTEGER";
    break;
  case CB_TAG_STRING:
    tag_string = "CB_TAG_STRING";
    break;
  case CB_TAG_ALPHABET_NAME:
    tag_string = "CB_TAG_ALPHABET_NAME";
    break;
  case CB_TAG_CLASS_NAME:
    tag_string = "CB_TAG_CLASS_NAME";
    break;
  case CB_TAG_LOCALE_NAME:
    tag_string = "CB_TAG_LOCALE_NAME";
    break;
  case CB_TAG_SYSTEM_NAME:
    tag_string = "CB_TAG_SYSTEM_NAME";
    break;
  case CB_TAG_SCHEMA_NAME:
    tag_string = "CB_TAG_SCHEMA_NAME";
    break;
  case CB_TAG_LITERAL:
    tag_string = "CB_TAG_LITERAL";
    break;
  case CB_TAG_DECIMAL:
    tag_string = "CB_TAG_DECIMAL";
    break;
  case CB_TAG_FIELD:
    tag_string = "CB_TAG_FIELD";
    break;
  case CB_TAG_FILE:
    tag_string = "CB_TAG_FILE";
    break;
  case CB_TAG_REPORT:
    tag_string = "CB_TAG_REPORT";
    break;
  case CB_TAG_CD:
    tag_string = "CB_TAG_CD";
    break;
  case CB_TAG_REFERENCE:
    tag_string = "CB_TAG_REFERENCE";
    break;
  case CB_TAG_BINARY_OP:
    tag_string = "CB_TAG_BINARY_OP";
    break;
  case CB_TAG_FUNCALL:
    tag_string = "CB_TAG_FUNCALL";
    break;
  case CB_TAG_CAST:
    tag_string = "CB_TAG_CAST";
    break;
  case CB_TAG_INTRINSIC:
    tag_string = "CB_TAG_INTRINSIC";
    break;
  case CB_TAG_LABEL:
    tag_string = "CB_TAG_LABEL";
    break;
  case CB_TAG_ASSIGN:
    tag_string = "CB_TAG_ASSIGN";
    break;
  case CB_TAG_INITIALIZE:
    tag_string = "CB_TAG_INITIALIZE";
    break;
  case CB_TAG_SEARCH:
    tag_string = "CB_TAG_SEARCH";
    break;
  case CB_TAG_CALL:
    tag_string = "CB_TAG_CALL";
    break;
  case CB_TAG_GOTO:
    tag_string = "CB_TAG_GOTO";
    break;
  case CB_TAG_IF:
    tag_string = "CB_TAG_IF";
    break;
  case CB_TAG_PERFORM:
    tag_string = "CB_TAG_PERFORM";
    break;
  case CB_TAG_STATEMENT:
    tag_string = "CB_TAG_STATEMENT";
    break;
  case CB_TAG_CONTINUE:
    tag_string = "CB_TAG_CONTINUE";
    break;
  case CB_TAG_CANCEL:
    tag_string = "CB_TAG_CANCEL";
    break;
  case CB_TAG_ALTER:
    tag_string = "CB_TAG_ALTER";
    break;
  case CB_TAG_SET_ATTR:
    tag_string = "CB_TAG_SET_ATTR";
    break;
  case CB_TAG_XML_PARSE:
    tag_string = "CB_TAG_XML_PARSE";
    break;
  case CB_TAG_PERFORM_VARYING:
    tag_string = "CB_TAG_PERFORM_VARYING";
    break;
  case CB_TAG_PICTURE:
    tag_string = "CB_TAG_PICTURE";
    break;
  case CB_TAG_LIST:
    tag_string = "CB_TAG_LIST";
    break;
  case CB_TAG_DIRECT:
    tag_string = "CB_TAG_DIRECT";
    break;
  case CB_TAG_DEBUG:
    tag_string = "CB_TAG_DEBUG";
    break;
  case CB_TAG_DEBUG_CALL:
    tag_string = "CB_TAG_DEBUG_CALL";
    break;
  case CB_TAG_PROGRAM:
    tag_string = "CB_TAG_PROGRAM";
    break;
  case CB_TAG_PROTOTYPE:
    tag_string = "CB_TAG_PROTOTYPE";
    break;
  case CB_TAG_DECIMAL_LITERAL:
    tag_string = "CB_TAG_DECIMAL_LITERAL";
    break;
  case CB_TAG_REPORT_LINE:
    tag_string = "CB_TAG_REPORT_LINE";
    break;
  case CB_TAG_ML_SUPPRESS:
    tag_string = "CB_TAG_ML_SUPPRESS";
    break;
  case CB_TAG_ML_TREE:
    tag_string = "CB_TAG_ML_TREE";
    break;
  case CB_TAG_ML_SUPPRESS_CHECKS:
    tag_string = "CB_TAG_ML_SUPPRESS_CHECKS";
    break;
  case CB_TAG_VARY:
    tag_string = "CB_TAG_VARY";
    break;
  case CB_TAG_TAB_VALS:
    tag_string = "CB_TAG_TAB_VALS";
    break;
  }
  fprintf(jsonfile, "%*s\"tag\": \"%s\",\n", depth, "", tag_string);
}

void output_cb_category(FILE *jsonfile, enum cb_category category) {
  char *category_string;

  switch (category) {
  case CB_CATEGORY_UNKNOWN:
    category_string = "CB_CATEGORY_UNKNOWN";
    break;
  case CB_CATEGORY_ALPHABETIC:
    category_string = "CB_CATEGORY_ALPHABETIC";
    break;
  case CB_CATEGORY_ALPHANUMERIC:
    category_string = "CB_CATEGORY_ALPHANUMERIC";
    break;
  case CB_CATEGORY_ALPHANUMERIC_EDITED:
    category_string = "CB_CATEGORY_ALPHANUMERIC_EDITED";
    break;
  case CB_CATEGORY_BOOLEAN:
    category_string = "CB_CATEGORY_BOOLEAN";
    break;
  case CB_CATEGORY_INDEX:
    category_string = "CB_CATEGORY_INDEX";
    break;
  case CB_CATEGORY_NATIONAL:
    category_string = "CB_CATEGORY_NATIONAL";
    break;
  case CB_CATEGORY_NATIONAL_EDITED:
    category_string = "CB_CATEGORY_NATIONAL_EDITED";
    break;
  case CB_CATEGORY_NUMERIC:
    category_string = "CB_CATEGORY_NUMERIC";
    break;
  case CB_CATEGORY_NUMERIC_EDITED:
    category_string = "CB_CATEGORY_NUMERIC_EDITED";
    break;
  case CB_CATEGORY_OBJECT_REFERENCE:
    category_string = "CB_CATEGORY_OBJECT_REFERENCE";
    break;
  case CB_CATEGORY_DATA_POINTER:
    category_string = "CB_CATEGORY_DATA_POINTER";
    break;
  case CB_CATEGORY_PROGRAM_POINTER:
    category_string = "CB_CATEGORY_PROGRAM_POINTER";
    break;
  case CB_CATEGORY_FLOATING_EDITED:
    category_string = "CB_CATEGORY_FLOATING_EDITED";
    break;
  case CB_CATEGORY_ERROR:
    category_string = "CB_CATEGORY_ERROR";
    break;
  }
  fprintf(jsonfile, "%*s\"category\": \"%s\",\n", depth, "", category_string);
}

void output_cb_tree_common(FILE *jsonfile, const struct cb_tree_common common) {
  fprintf(jsonfile, "%*s\"common\": {\n", depth, "");
  depth = depth + 4;
  output_cb_tag(jsonfile, common.tag);
  output_cb_category(jsonfile, common.category);
  fprintf(jsonfile, "%*s\"source_file\": \"%s\",\n", depth, "",
          common.source_file);
  fprintf(jsonfile, "%*s\"source_line\": %d, \n", depth, "",
          common.source_line);
  fprintf(jsonfile, "%*s\"source_column\": %d \n", depth, "",
          common.source_column);
  depth = depth - 4;
  fprintf(jsonfile, "%*s},\n", depth, "");
}

void output_cb_program(FILE *jsonfile,
                       const struct cb_program *current_program) {
  if (depth == 0) {
    /* This is the top-level opening paranthesis. */
    fputs("{\n", jsonfile);
  }

  depth = depth + 4;

  /* Output each field */
  /* common */
  output_cb_tree_common(jsonfile, current_program->common);

  /* next_program */
  fprintf(jsonfile, "%*s\"next_program\": ", depth, "");
  if (current_program->next_program) {
    fputs("{\n", jsonfile);
    output_cb_program(jsonfile, current_program->next_program);
  } else {
    fputs("null, \n", jsonfile);
  }

  /* next_program_ordered */
  fprintf(jsonfile, "%*s\"next_program_ordered\": ", depth, "");
  if (current_program->next_program_ordered) {
    fputs("{\n", jsonfile);
    output_cb_program(jsonfile, current_program->next_program_ordered);
  } else {
    fputs("null, \n", jsonfile);
  }

  /* program_name */
  fprintf(jsonfile, "%*s\"program_name\": \"%s\",\n", depth, "",
          current_program->program_name);
  /* program_id */
  fprintf(jsonfile, "%*s\"program_id\": \"%s\",\n", depth, "",
          current_program->program_id);

  /* source_name */
  fprintf(jsonfile, "%*s\"source_name\": \"%s\",\n", depth, "",
          current_program->source_name);

  /* orig_program_id */
  fprintf(jsonfile, "%*s\"orig_program_id\": \"%s\",\n", depth, "",
          current_program->orig_program_id);

  depth = depth - 4;
  fprintf(jsonfile, "%*s}\n", depth, "");
}

void dump_ast_as_json(const struct cb_program *current_program,
                      char *filename) {
  strcat(filename, ".json");
  FILE *jsonfile = fopen(filename, "w");

  output_cb_program(jsonfile, current_program);
}