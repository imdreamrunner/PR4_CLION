/*
 * Complete this file and run rpcgen -MN minifyjpeg.x
 */

struct rpc_minify_in {
 opaque src<>;
 int src_len;
 int dst_len;
};
struct rpc_minify_out {
 opaque dest<>;
};

program RPC_MINIFY_JPEG_PROG { /* RPC service name */
  version RPC_MINIFY_JPEG_VERS {
    rpc_minify_out RPC_MINIFY_JPEG_PROC(rpc_minify_in) = 1; /* proc1 */
  } = 1; /* version1 */
} = 0x31230000; /* service id */






