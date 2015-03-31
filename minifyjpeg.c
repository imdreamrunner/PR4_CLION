

#include "minifyjpeg.h"
#include "magickminify.h"

/* Implement the needed server-side functions here */


rpc_minify_out * rpc_minify_jpeg_proc_1(rpc_minify_in in , CLIENT * client){

    magickminify_init();

    char* src_binary = malloc(in.src_len);
    memcpy(src_binary,in.src,in.src_len);

    ssize_t src_length = in.src_len;
    ssize_t dst_length = in.dst_len;

    rpc_minify_out * out;
    out->dest = magickminify(src_binary,src_length,&dst_length);

    magickminify_cleanup();
    free(src_binary);

    return out;

}




