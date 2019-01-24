/* $CORTO_GENERATED
 *
 * json.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <driver.ext.json>

static int json_loadFile(corto_string file, int argc, char* argv[], void* ctx) {
    ut_log_push("json");
    char *json = ut_file_load(file);
    if (!json) {
        ut_throw("cannot find file '%s'", file);
        goto error;
    }
    ut_log_pop();
    int result = json_toObject(NULL, NULL, json);
    free(json);
    return result;
error:
    return -1;
}

int cortomain(int argc, char *argv[]) {

    ut_log_push("json");
    ut_load_register("json", json_loadFile, NULL);
    ut_log_pop();

    return 0;
}
