


#include "minifyjpeg_xdr.c"


#include "minifyjpeg_clnt.c"
#include "minifyjpeg.h"


void* minify_via_rpc(CLIENT* clnt, void* src_val, size_t src_len, size_t *dst_len){
  /*
    * Use RPC to obtain a minified version of the jpeg image
    * stored in the array src_val and having src_len bytes.
    */
  //-------CLIENT SIDE CODE HERE--------
//create client

  struct rpc_minify_out * service_out = malloc(sizeof(*service_out));
  struct rpc_minify_in service_in;

  //printf("src val: %s\n",(char*)src_val);
  memcpy(service_in.src.src_val,src_val,src_len);
  //printf("service_in.src val: %s\n",service_in.src.src_val);

  service_in.src.src_len = src_len;

  printf("FILE LEN INSIDE MINIFY FUNCTION IS %u\n\n",service_in.src.src_len);
  printf("calling rpc_minify_jpeg_proc1\n");

  service_out =  rpc_minify_jpeg_proc_1(service_in,clnt);

  printf("New file length is: %u\n\n",service_out->dest.dest_len);

  size_t dlen = service_out->dest.dest_len;
  dst_len = &dlen;

  printf("dstlen pointer is %zu\n",*dst_len);

  void* return_buffer = malloc(service_out->dest.dest_len);
  printf("copying service_out buffer to return buffer\n");

  memcpy(return_buffer,service_out->dest.dest_val,service_out->dest.dest_len);

  printf("return retrieved buffer");

  return return_buffer;
}



CLIENT* get_minify_client(char *server) {
  CLIENT *clnt;
  if ((clnt = clnt_create(server,RPC_MINIFY_JPEG_PROG,RPC_MINIFY_JPEG_VERS, "tcp")) == NULL)
  {
    /*
    * can't establish connection with server
    */
    clnt_pcreateerror(server);
    exit(2);
  }

  return clnt;
}