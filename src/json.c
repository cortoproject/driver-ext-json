/* $CORTO_GENERATED
 *
 * json.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <driver/ext/json/json.h>

static int json_loadFile(corto_string file, int argc, char* argv[], void* ctx) {
    corto_component_push("json");
    char *json = corto_fileLoad(file);
    if (!json) {
        corto_seterr("cannot find file '%s'", file);
        goto error;
    }
    corto_component_pop();
    int result = json_toObject(NULL, json);
    corto_dealloc(json);
    return result;
error:
    return -1;
}

int cortomain(int argc, char *argv[]) {

    corto_component_push("json");
    corto_load_register("json", json_loadFile, NULL);
    corto_component_pop();

    return 0;
}
