/*
 * Copyright (c) 2001 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ident "$Id: d-generic.c,v 1.5 2001/09/01 02:01:30 steve Exp $"

# include  "device.h"
# include  "fpga_priv.h"
# include  <assert.h>

/*
 * This is the device emitter for the most generic FPGA. It doesn't
 * know anything special about device types, so can't handle complex
 * logic.
 */

static void generic_show_logic(ivl_net_logic_t net)
{
      char name[1024];
      ivl_nexus_t nex;
      unsigned idx;

      mangle_logic_name(net, name, sizeof name);

      switch (ivl_logic_type(net)) {

	  case IVL_LO_AND:
	    fprintf(xnf, "SYM, %s, AND, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    for (idx = 1 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
		  char ipin[32];
		  nex = ivl_logic_pin(net, idx);
		  sprintf(ipin, "I%u", idx-1);
		  draw_pin(nex, ipin, 'I');
	    }
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_BUF:
	    assert(ivl_logic_pins(net) == 2);
	    fprintf(xnf, "SYM, %s, BUF, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    nex = ivl_logic_pin(net, 1);
	    draw_pin(nex, "I", 'I');
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_NAND:
	    fprintf(xnf, "SYM, %s, NAND, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    for (idx = 1 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
		  char ipin[32];
		  nex = ivl_logic_pin(net, idx);
		  sprintf(ipin, "I%u", idx-1);
		  draw_pin(nex, ipin, 'I');
	    }
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_NOR:
	    fprintf(xnf, "SYM, %s, NOR, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    for (idx = 1 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
		  char ipin[32];
		  nex = ivl_logic_pin(net, idx);
		  sprintf(ipin, "I%u", idx-1);
		  draw_pin(nex, ipin, 'I');
	    }
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_NOT:
	    assert(ivl_logic_pins(net) == 2);
	    fprintf(xnf, "SYM, %s, INV, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    nex = ivl_logic_pin(net, 1);
	    draw_pin(nex, "I", 'I');
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_OR:
	    fprintf(xnf, "SYM, %s, OR, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    for (idx = 1 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
		  char ipin[32];
		  nex = ivl_logic_pin(net, idx);
		  sprintf(ipin, "I%u", idx-1);
		  draw_pin(nex, ipin, 'I');
	    }
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_XOR:
	    fprintf(xnf, "SYM, %s, XOR, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    for (idx = 1 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
		  char ipin[32];
		  nex = ivl_logic_pin(net, idx);
		  sprintf(ipin, "I%u", idx-1);
		  draw_pin(nex, ipin, 'I');
	    }
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_XNOR:
	    fprintf(xnf, "SYM, %s, XNOR, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    for (idx = 1 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
		  char ipin[32];
		  nex = ivl_logic_pin(net, idx);
		  sprintf(ipin, "I%u", idx-1);
		  draw_pin(nex, ipin, 'I');
	    }
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_BUFIF0:
	    fprintf(xnf, "SYM, %s, TBUF, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    nex = ivl_logic_pin(net, 1);
	    draw_pin(nex, "I", 'I');
	    nex = ivl_logic_pin(net, 2);
	    draw_pin(nex, "~T", 'I');
	    fprintf(xnf, "END\n");
	    break;

	  case IVL_LO_BUFIF1:
	    fprintf(xnf, "SYM, %s, TBUF, LIBVER=2.0.0\n", name);
	    nex = ivl_logic_pin(net, 0);
	    draw_pin(nex, "O", 'O');
	    nex = ivl_logic_pin(net, 1);
	    draw_pin(nex, "I", 'I');
	    nex = ivl_logic_pin(net, 2);
	    draw_pin(nex, "T", 'I');
	    fprintf(xnf, "END\n");
	    break;

	  default:
	    fprintf(stderr, "fpga.tgt: unknown logic type %u\n",
		    ivl_logic_type(net));
	    break;
      }

}

static void generic_show_dff(ivl_lpm_t net)
{
      char name[1024];
      ivl_nexus_t nex;

      mangle_lpm_name(net, name, sizeof name);

      fprintf(xnf, "SYM, %s, DFF, LIBVER=2.0.0\n", name);

      nex = ivl_lpm_q(net, 0);
      draw_pin(nex, "Q", 'O');

      nex = ivl_lpm_data(net, 0);
      draw_pin(nex, "D", 'I');

      nex = ivl_lpm_clk(net);
      draw_pin(nex, "C", 'I');

      if ((nex = ivl_lpm_enable(net)))
	    draw_pin(nex, "CE", 'I');

      fprintf(xnf, "END\n");
}

/*
 * The generic == comparator uses EQN records to generate 2-bit
 * comparators, that are then connected together by a wide AND gate.
 */
static void generic_show_cmp_eq(ivl_lpm_t net)
{
      ivl_nexus_t nex;
      unsigned idx;
      char name[1024];
	/* Make this many dual pair comparators, and */
      unsigned deqn = ivl_lpm_width(net) / 2;
	/* Make this many single pair comparators. */
      unsigned seqn = ivl_lpm_width(net) % 2;

      mangle_lpm_name(net, name, sizeof name);

      for (idx = 0 ;  idx < deqn ;  idx += 1) {
	    fprintf(xnf, "SYM, %s/CD%u, EQN, "
		    "EQN=(~((I0 @ I1) + (I2 @ I3)))\n",
		    name, idx);

	    fprintf(xnf, "    PIN, O, O, %s/CDO%u\n", name, idx);

	    nex = ivl_lpm_data(net, 2*idx);
	    draw_pin(nex, "I0", 'I');
	    nex = ivl_lpm_datab(net, 2*idx);
	    draw_pin(nex, "I1", 'I');

	    nex = ivl_lpm_data(net, 2*idx+1);
	    draw_pin(nex, "I2", 'I');
	    nex = ivl_lpm_datab(net, 2*idx+1);
	    draw_pin(nex, "I3", 'I');

	    fprintf(xnf, "END\n");
      }

      if (seqn != 0) {
	    fprintf(xnf, "SYM, %s/CT, XNOR, LIBVER=2.0.0\n", name);

	    fprintf(xnf, "    PIN, O, O, %s/CTO\n", name);

	    nex = ivl_lpm_data(net, 2*deqn);
	    draw_pin(nex, "I0", 'I');

	    nex = ivl_lpm_datab(net, 2*deqn);
	    draw_pin(nex, "I1", 'I');

	    fprintf(xnf, "END\n");
      }

      if (ivl_lpm_type(net) == IVL_LPM_CMP_EQ)
	    fprintf(xnf, "SYM, %s/OUT, AND, LIBVER=2.0.0\n", name);
      else
	    fprintf(xnf, "SYM, %s/OUT, NAND, LIBVER=2.0.0\n", name);

      nex = ivl_lpm_q(net, 0);
      draw_pin(nex, "O", 'O');

      for (idx = 0 ;  idx < deqn ;  idx += 1)
	    fprintf(xnf, "    PIN, I%u, I, %s/CDO%u\n", idx, name, idx);

      for (idx = 0 ;  idx < seqn ;  idx += 1)
	    fprintf(xnf, "    PIN, I%u, I, %s/CTO\n", deqn+idx, name);

      fprintf(xnf, "END\n");
}

const struct device_s d_generic = {
      generic_show_logic,
      generic_show_dff,
      generic_show_cmp_eq,
      generic_show_cmp_eq
};


/*
 * $Log: d-generic.c,v $
 * Revision 1.5  2001/09/01 02:01:30  steve
 *  identity compare, and PWR records for constants.
 *
 * Revision 1.4  2001/08/31 23:02:13  steve
 *  Relax pin count restriction on logic gates.
 *
 * Revision 1.3  2001/08/31 04:17:56  steve
 *  Many more logic gate types.
 *
 * Revision 1.2  2001/08/31 02:59:06  steve
 *  Add root port SIG records.
 *
 * Revision 1.1  2001/08/28 04:14:20  steve
 *  Add the fpga target.
 *
 */

