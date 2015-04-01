


#include "minifyjpeg_xdr.c"


#include "minifyjpeg_clnt.c"

void* minify_via_rpc(char* server, void* src_val, size_t src_len, size_t *dst_len){
  /*
    * Use RPC to obtain a minified version of the jpeg image
    * stored in the array src_val and having src_len bytes.
    */
  //-------CLIENT SIDE CODE HERE--------
//create client

  rpc_minify_out * service_out;
  rpc_minify_in service_in; 
 
  CLIENT *clnt;
	  if ((cl = clnt_create(server,RPC_MINIFY_JPEG_PROG,RPC_MINIFY_JPEG_VERS, "tcp")) == NULL) {
        /*
        * can't establish connection with server
        */
        clnt_pcreateerror(server);
        exit(2);
    }
    else
    {
    service_in.src_val = src_val;
    service_in.src_len = src_len;
    service_in.dst_len = dst_len;
      
    void* out.buffer = whateve rthe service is ( params );
    service_out =  rpc_minify_jpeg_proc_1_svc();
    
    }
    
  return service_out.dst_val????;
}
