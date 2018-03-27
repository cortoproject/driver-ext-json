/* $CORTO_GENERATED
 *
 * json.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <driver/ext/json/json.h>

static int json_loadFile(corto_string file, int argc, char* argv[], void* ctx) {
    corto_log_push("json");
    char *json = corto_file_load(file);
    if (!json) {
        corto_throw("cannot find file '%s'", file);
        goto error;
    }
    corto_log_pop();
    int result = json_toObject(NULL, NULL, json);
    corto_dealloc(json);
    return result;
error:
    return -1;
}

int cortomain(int argc, char *argv[]) {

    corto_log_push("json");
    corto_load_register("json", json_loadFile, NULL);
    corto_log_pop();

    return 0;
}
